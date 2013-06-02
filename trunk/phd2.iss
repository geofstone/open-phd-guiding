; PHD2 installer script
; Generated by Bret McKee on 2013/03/23
;
; Note: This script is just for the alpha release right now. It does not
;       include any DLLs, libraraies or anything else.  It assumes that it
;       is being installed on a system that already has PHD v1 installed

#define APP_VERSION "2.0.4a"

[Setup]
AppName=phd2
AppVersion={#APP_VERSION}
DefaultDirName={pf}\PHDGuiding
DefaultGroupName="PHD Guiding"
UninstallDisplayIcon={app}\phd2.exe
Compression=lzma2
SolidCompression=yes
OutputDir=.
OutputBaseFilename="phd2-v{#APP_VERSION}-installer"
DirExistsWarning=no

[Files]
Source: "release\phd2.exe"; DestDir: "{app}"; Flags: replacesameversion
Source: "locales\*"; Excludes: "*-old.*"; DestDir: "{app}\locales"; Flags: recursesubdirs replacesameversion
Source: "README-Release.txt"; DestDir: "{app}"; Flags: isreadme

[Icons]
Name: "{group}\PHD2 Guiding"; FileName: "{app}\phd2.exe"

[Run]
Filename: {app}\phd2.exe; Description: "Launch PHD2 after installation"; Flags: nowait postinstall skipifsilent

[Code]
function NextButtonClick(PageId: Integer): Boolean;
begin
    Result := True;
    if (PageId = wpSelectDir) and not FileExists(ExpandConstant('{app}\phd.exe')) then begin
        MsgBox('PHD does not seem to be installed in that folder.  Please select the correct folder.', mbError, MB_OK);
        Result := False;
        exit;
    end;
end;
