// geodeModsInstaller.cpp: определяет точку входа для приложения.
//

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <filesystem>
using namespace std;
int main(int argc, char** argv) {

    HWND hConsole = GetForegroundWindow();
    ShowWindow(hConsole, SW_HIDE);

    char cCurrentPath[MAX_PATH]; //vvv holly molyy dss its finally not doin wtf things vvv
    std::filesystem::path me = std::string(cCurrentPath, GetModuleFileName(NULL, cCurrentPath, MAX_PATH));

    std::filesystem::path mod;
    if (argc == 1) {
        int msgboxID = MessageBox(nullptr, ("U must \"open\" .geode file using \"open with\" feature. (create file associations)\nAlso u can drag .geode file to me.\n\n\n"), "How to use:", MB_OK | MB_ICONWARNING);
        return msgboxID;
    }
    else mod = argv[1];

    int msgboxID = MessageBox(nullptr,
        ("Mod:\n" + mod.string() + "\n\n" + "Geode mods folder:\n" + (me.parent_path() / "mods").string()).c_str(),
        "Install .geode mod", MB_OKCANCEL | MB_ICONINFORMATION);

    if (msgboxID == IDOK) {
        try {
            std::filesystem::rename(mod, (me.parent_path() / "mods") / mod.filename());
            MessageBox(nullptr, ("Mod:\n" + ((me.parent_path() / "mods") / mod.filename()).string()).c_str(),
                "Installed .geode mod", MB_OK | MB_ICONINFORMATION);
        }
        catch (std::filesystem::filesystem_error& e) {
            std::cout << e.what() << '\n';
            MessageBox(nullptr, e.what(), "Install .geode mod fail", MB_OK | MB_ICONERROR);
        }
    }

    return 0;
}