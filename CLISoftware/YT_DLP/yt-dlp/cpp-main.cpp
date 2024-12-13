#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

void fullPlaylistDownload();

int main (int argc, char *argv[]) {
    // TODO: add a proper video command and accept argument
    // TODO:    if there is a folder with the same name on /music/folder, change the old-folder name to
    //          folder-old or make only the new downloaded files to be sent to the device.
    //          for example: _mu_vlaspatta has a bunch of musics. as if i want to download the recently added
    //          musics and send only them to my mobile device, since the older files are already there
    bool flag_single_music = false, flag_full_playlist = false, flag_video = false, flag_kdeconnect = true;

    const std::string basePath("/home/gokbuck/Videos/yt_dlp/music/");
    const std::string singleMusicPath(basePath + "_mu_noplaylist/");
    const std::string fullPlaylist("yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P "+basePath+" LINK --replace-in-metadata \"playlist\" \"[ /]\" \"_\" -o '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s'");
    const std::string singleMusic("yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P "+basePath+" LINK -o '_mu_noplaylist/%(title)s.%(ext)s'");

    int i = 1;
    std::string _path;
    std::string finalCmd;
    if (argc == 2 && strcmp(argv[i], "-l") != 0) {
        flag_full_playlist = true;
        finalCmd = "yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P "+basePath+" "+argv[i]+" --replace-in-metadata \"playlist\" \"[ /]\" \"_\" -o '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s'";
        _path= "$(echo \""+basePath+"$(yt-dlp --print playlist --replace-in-metadata \"playlist\" \"[ /]\" \"_\" "+argv[i]+")\" | head -n 1)";
        ++i;
    }
    while (i < argc) {
        if (strcmp(argv[i], "-l") == 0) {
            std::cout << "-fp LINK \t:download playlist\n-sm LINK \t:download single music\n--no-kde \t:do not use kdeconnect\n";
            std::cout << "note: --no-kde must be used along other flags, otherwise it will malfunction.\n";
            return 0;
        } else if (strcmp(argv[i], "-fp") == 0) {
            flag_full_playlist = true;
            finalCmd = "yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P "+basePath+" "+argv[++i]+" --replace-in-metadata \"playlist\" \"[ /]\" \"_\" -o '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s'";
            _path= "$(echo \""+basePath+"$(yt-dlp --restrict-filenames --print playlist --replace-in-metadata \"playlist\" \"[ /]\" \"_\" "+argv[i]+")\" | head -n 1)";
        } else if (strcmp(argv[i], "-sm") == 0) {
            flag_single_music = true;
            std::string link;
            std::cin >> link;
            finalCmd = "yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P "+basePath+" "+link+" -o '_mu_noplaylist/%(title)s.%(ext)s'";
            //finalCmd = "yt-dlp -f 'ba' -x --audio-format mp3 --embed-thumbnail -P "+basePath+" "+argv[++i]+" -o '_mu_noplaylist/%(title)s.%(ext)s'";
            _path = "$(echo \""+singleMusicPath+"$(yt-dlp --print \"%(title)s.mp3\" "+link+")\" | head -n 1)";
            //_path = "$(echo \""+singleMusicPath+"$(yt-dlp --print \"%(title)s.mp3\" "+argv[i]+")\" | head -n 1)";
        }
        if (strcmp(argv[i], "--no-kde") == 0) {
            flag_kdeconnect = false;
        }
        i++;
    }

    std::system(finalCmd.c_str());

    std::string finalPath;
    if (flag_kdeconnect == true) {
        std::system("rm /tmp/files.zip");
        if (flag_full_playlist == true) {
            // zip all files
            std::system(("zip /tmp/files.zip "+_path+"/*").c_str());
        } else if (flag_single_music == true) {
            // zip single file
                std::system(("zip /tmp/files.zip \""+_path+"\"").c_str());
        }
        const std::string kdeconnect("kdeconnect-cli -d $(kdeconnect-cli -a --id-only) --share /tmp/files.zip");
        std::system(kdeconnect.c_str());
    }

    return 0;
}
