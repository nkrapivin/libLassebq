/// libLassebq injector script
/// @author Nikita Krapivin
/// @version v1.2.0
/// The latest release of UndertaleModTool is required to run this script.
/// I am sorry. But hey, no more ram.dll hack!

using System.Linq; // needed for the .Where() method

void InjectDLL()
{
	Data.Extensions.Add(new UndertaleExtension()
	{
		ClassName = Data.Strings.MakeString(""),
		FolderName = Data.Strings.MakeString(""),
		Name = Data.Strings.MakeString("libLassebq"),
		Files = new UndertalePointerList<UndertaleExtensionFile>()
		{
			new UndertaleExtensionFile()
			{
				Filename = Data.Strings.MakeString("libLassebq.dll"),
				InitScript = Data.Strings.MakeString("lassebq_init"),
				CleanupScript = Data.Strings.MakeString("lassebq_shutdown"),
				Kind = UndertaleExtensionKind.DLL,
				Functions = new UndertalePointerList<UndertaleExtensionFunction>()
				{
					new UndertaleExtensionFunction()
					{
						ID = Data.ExtensionFindLastId(),
						ExtName = Data.Strings.MakeString("lassebq_init"),
						Kind = 11,
						Name = Data.Strings.MakeString("lassebq_init"),
						Arguments = new UndertaleSimpleList<UndertaleExtensionFunctionArg>(),
						RetType = UndertaleExtensionVarType.Double
					},
					new UndertaleExtensionFunction()
					{
						ID = Data.ExtensionFindLastId(),
						ExtName = Data.Strings.MakeString("lassebq_shutdown"),
						Kind = 11,
						Name = Data.Strings.MakeString("lassebq_shutdown"),
						Arguments = new UndertaleSimpleList<UndertaleExtensionFunctionArg>(),
						RetType = UndertaleExtensionVarType.Double
					},
					new UndertaleExtensionFunction()
					{
						ID = Data.ExtensionFindLastId(),
						ExtName = Data.Strings.MakeString("RegisterCallbacks"),
						Kind = 11,
						Name = Data.Strings.MakeString("lassebq_RegisterCallbacks"),
						Arguments = new UndertaleSimpleList<UndertaleExtensionFunctionArg>()
						{
							new UndertaleExtensionFunctionArg() { Type = UndertaleExtensionVarType.String },
							new UndertaleExtensionFunctionArg() { Type = UndertaleExtensionVarType.String },
							new UndertaleExtensionFunctionArg() { Type = UndertaleExtensionVarType.String },
							new UndertaleExtensionFunctionArg() { Type = UndertaleExtensionVarType.String },
						},
						RetType = UndertaleExtensionVarType.Double
					}
				}
			}
		}
	});

	// add productid.
	Data.FORM.EXTN.productIdData.Add(System.Text.Encoding.ASCII.GetBytes("LIBLASSEBQYYCDLL"));
	// NOTE: will probably be moved over to the UndertaleExtension class itself in the near future.
}

bool IsNotAdded()
{
	int possible = Data.Extensions.Where(x => x.Name.Content == "libLassebq").Count();
	if (possible > 0)
	{
		ScriptError("libLassebq is already added, consider restoring from a backup?", "Error");
		return false;
	}

	return true;
}

bool ScriptEntry() // true - ok, false - any kind of an error.
{
	// We start here.
	if (!IsNotAdded()) return false;
	if (!ScriptQuestion("This will modify your .win, be sure to make a backup, proceed?")) return false;
	InjectDLL();
	ScriptMessage("Done! Save the .win and start the game.");
	return true;
}

ScriptEntry();