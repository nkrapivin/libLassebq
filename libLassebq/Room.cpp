#include "Room.h"
#include "libLassebq.h"

CRoom** g_RunRoom = nullptr; // this variable was only used to find instances, it is not used anymore!
CHash<CInstance>* g_CInstanceHashList = nullptr;
int* g_New_Room = nullptr;

const int FLAG_deactivated = 1;

CInstance* lass_find_CInstance_QUICK(int obj_index) {

	// any instances of this object exist in the first place.
	for (HashNode<CInstance>* node = g_CInstanceHashList->m_pHashingTable[g_CInstanceHashList->m_HashingMask & obj_index].m_pFirst;
		node != nullptr;
		node = node->m_pNext) {
		// be sure
		if (node->m_ID == obj_index && node->m_pObj != nullptr) {
			// check if the instance is not marked as deactivated.
			if ((node->m_pObj->m_Instflags & FLAG_deactivated) == 0) {
				return node->m_pObj;
			}
		}
	}

	return nullptr;
}