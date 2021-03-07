/// libLassebq injector script
/// @author Nikita Krapivin
/// @version v1.1.0

using System.Linq; // needed for the .Where() method

void InjectDLL()
{
	Data.Extensions.Add(new UndertaleExtension()
	{
		ClassName = Data.Strings.MakeString(""),
		EmptyString = Data.Strings.MakeString(""),
		Name = Data.Strings.MakeString("libLassebq"),
		Files = new UndertalePointerList<UndertaleExtension.ExtensionFile>()
		{
			new UndertaleExtension.ExtensionFile()
			{
				Filename = Data.Strings.MakeString("libLassebq.dll"),
				InitScript = Data.Strings.MakeString("lassebq_init"),
				CleanupScript = Data.Strings.MakeString("lassebq_shutdown"),
				Kind = UndertaleExtension.ExtensionKind.DLL,
				Functions = new UndertalePointerList<UndertaleExtension.ExtensionFunction>()
				{
					new UndertaleExtension.ExtensionFunction()
					{
						ID = 1,
						ExtName = Data.Strings.MakeString("lassebq_init"),
						Kind = 11,
						Name = Data.Strings.MakeString("lassebq_init"),
						Arguments = new UndertaleSimpleList<UndertaleExtension.ExtensionFunctionArg>(),
						RetType = UndertaleExtension.ExtensionVarType.Double
					},
					new UndertaleExtension.ExtensionFunction()
					{
						ID = 2,
						ExtName = Data.Strings.MakeString("lassebq_shutdown"),
						Kind = 11,
						Name = Data.Strings.MakeString("lassebq_shutdown"),
						Arguments = new UndertaleSimpleList<UndertaleExtension.ExtensionFunctionArg>(),
						RetType = UndertaleExtension.ExtensionVarType.Double
					},
					new UndertaleExtension.ExtensionFunction()
					{
						ID = 3,
						ExtName = Data.Strings.MakeString("RegisterCallbacks"),
						Kind = 11,
						Name = Data.Strings.MakeString("lassebq_RegisterCallbacks"),
						Arguments = new UndertaleSimpleList<UndertaleExtension.ExtensionFunctionArg>()
						{
							new UndertaleExtension.ExtensionFunctionArg() { Type = UndertaleExtension.ExtensionVarType.String },
							new UndertaleExtension.ExtensionFunctionArg() { Type = UndertaleExtension.ExtensionVarType.String },
							new UndertaleExtension.ExtensionFunctionArg() { Type = UndertaleExtension.ExtensionVarType.String },
							new UndertaleExtension.ExtensionFunctionArg() { Type = UndertaleExtension.ExtensionVarType.String },
						},
						RetType = UndertaleExtension.ExtensionVarType.Double
					}
				}
			}
		}
	});

	// add productid.
	Data.FORM.EXTN.productIdData.Add(System.Text.Encoding.ASCII.GetBytes("LIBLASSEBQYYCDLL"));
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