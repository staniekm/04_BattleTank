// Marcin Staniek Game Dev Course 2020

using UnrealBuildTool;
using System.Collections.Generic;

public class BattleTankEditorTarget : TargetRules
{
    public BattleTankEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        ExtraModuleNames.Add("BattleTank");
    }
}