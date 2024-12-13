# Livro.txt


## wget download from Site
    wget -P pictures -nd -r -l 1 -H -D i.SiteCdn.org -A png,gif,jpg,jpeg,webm [thread-url]

## find application directory
    ls -la `which discord`

## convert from png to pdf
    convert *.png output.pdf

## substitute word multiple times on vim
    :%s/como_estava/como_quiser/gc #c para escolher entre quais substituir ou nao
    ::: more at https://e-tinet.com/linux/vim-comandos/

## download an entire music playlist
    yt-dlp -f 'ba' -x --audio-format mp3 https://youtube.com/playlist?list=OLAK5uy_mi2Rcyu1-dWfsDCOa82Vvr193pAxSwZL0 -o '%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s'

## send file via kdeconnect-cli
    kdeconnect-cli -d $(kdeconnect-cli -a --id-only) --share /home/gokbuck/Videos/yt_dlp/music/*

## advanced system monitor
    bpytop

## restart graphical ambient kde plasma 
    plasmashell & (para versoes > 5.0)  || kstart5 plasmashell

## same as cat -n but show line numbers 
    nl

## shows files size 
    ls -lh

## choose default application to open certain file ext
    mimeopen -d your_video.avi

## strings in python
    ::: more at https://docs.python.org/3/library/string.html

## remove program but /home files
    pacman -Rns

## search for directories
    find -iwholename txt

## list use case examples of a program
    tldr pdftk  

## zip and unzip
    zip -9 -r -e final.zip initial/
    unzip final.zip

## compile in C using gcc 
    gcc -Wall main.c -o main
    -Wall = diretiva de compilacao (aponta possiveis descuidos do codigo programado)

## make webms
  ffmpeg -i filename.mp4 -c:v libvpx -crf 4 -b:v 1200K -vf scale=640:-1 -an output_name.webm
     ^ However this won't do sound, for that you'll use
  ffmpeg -i filename.mp4 -c:v libvpx -crf 4 -b:v 1200K -vf scale=640:-1 -c:a libvorbis output_name.webm
     ^ to have sound

## file size optimization ffmpeg
    comando para mp4 indicado pelo stackoverflow: 
    ffmpeg -i input.mp4 -vcodec libx265 -crf 28 output.mp4

## asus x555l x555u
    https://www.insidemylaptop.com/complete-disassembly-of-asus-x555l-x555u-series/

## activate web page scroll
      overflow:visible !important;
      document.body.style.overflow = "visible !important";
      function KeyPress(e) {
      var evtobj = window.event? event : e
      if (evtobj.keyCode == 90) {
        window.scrollBy(0, 100) 
      }
      if (evtobj.keyCode == 65) {
        window.scrollBy(0, -100) 
      }
    } 
    document.onkeydown = KeyPress;

## bash commands list 
    http://www.dicasparacomputador.com/guia-de-comandos-bash-do-terminal-para-linux

## more info about disk or pendrive
    sudo fdisk -l ='lista todos os discos disponiveis e informações sobre cada um deles'
    fdisk /dev/sbXx = para formatar o pendrive

## prime numbers algorithm
    ::: more at https://www.baeldung.com/cs/prime-number-algorithms

## improved file i/o memory mapping python
    ::: more at https://realpython.com/python-mmap/

## HolyC Programming 
    ::: more at https://duckduckgo.com/?q=holyc&ia=web

## Systemd
    ::: more at https://duckduckgo.com/?q=systemd&ia=web

## Bash Scripting Cheatsheet
    ::: more at https://devhints.io/bash

## Solutions Architect
    ::: more at https://www.intellectsoft.net/blog/what-is-solutions-architect/

## IT heirarchy of PRESTIGE
    solutions architects
    cloud engineers
    software engineers
    data engineers
    front end developers
    network engineers
    devops engineers
    systems engineers
    integration/ test engineers
    QA
    change control/deployment engineers
    systems operations
    client support
    IT help desk

## Compress PDF / pdf compression 
    ::: more at https://www.hostnextra.com/kb/how-to-compress-pdf-file-size-in-linux-cli/

## Convert PNG to PDF || JPG to PDF 
		::: more at https://www.linuxquestions.org/questions/linux-newbie-8/command-line-to-convert-png-to-pdf-4175519718/

## YT-DLP man page 
		::: more at ttps://www.mankier.com/1/yt-dlp

## DISCORD UPDATE 
  ls -la `which discord` //encontra o dir da aplicacao
  cd /path/
  cp build_info.json build_info.json.bkp
  vim build_info.json // change here the version number to the newest  

## module operator use on bc calc
    scale = 0 (after that can use modulo properly)
    ::: more at https://superuser.com/questions/31445/gnu-bc-modulo-with-scale-other-than-0

## to whenever i have problems with fonts 
    sudo pacman -S noto-fonts noto-fonts-cjk noto-fonts-emoji noto-fonts-extra

## the ultimate ffmpeg webm guide
    ::: more at https://raw.githubusercontent.com/VP8M8/WebM-Guide/master/ffmpeg_WebM_Guide_v1.0.1.png

## mp4 to webm
    ffmpeg -i input.mp4 -c:v libvpx-vp9 -b:v 1M -c:a libopus output.webm
    ::: more at https://wiki.installgentoo.com/index.php/WebM

## Commands to cut videos in half horizontally or vertically, and rejoin them later
    > vertical (top/bottom)
    ffmpeg -i input -filter_complex "[0]crop=iw:ih/2:0:0[top];[0]crop=iw:ih/2:0:oh[bottom]" -map "[top]" top.mp4 -map "[bottom]" bottom.mp4
    > horizontal (left/right)
    ffmpeg -i input -filter_complex "[0]crop=iw/2:ih:0:0[left];[0]crop=iw/2:ih:ow:0[right]" -map "[left]" left.mp4 -map "[right]" right.mp4
    ::: more at https://stackoverflow.com/questions/52582215/commands-to-cut-videos-in-half-horizontally-or-vertically-and-rejoin-them-later

## tools to retrieve video file information from command line
    ffprobe a.mp4
    exiftool a.mp4
    mediainfo input.mkv

## how to crop a video with ffmpeg
    > Cropping with 2 parameters : 
    ffmpeg -i input.mp4 -vf crop=600:400 output.mp4
    > Cropping with 4 parameters
    ffmpeg -i input.mp4 -vf crop=600:400:500:300 output.mp4
    ::: more at: https://youtu.be/CHQKGRwxao4

## discord compressed video ffmpeg vp9
   ffmpeg -i output.mp4 -c:v libvpx-vp9 -minrate (25-40% original bitrate) -maxrate *k -b:v *k output3.webm
   ::: more at https://support.discord.com/hc/en-us/community/posts/360051091674-Support-Video-Playback-for-HEVC-H-265-Videos
   ::: more at https://trac.ffmpeg.org/wiki/Encode/VP9
   ::: more at https://superuser.com/questions/1106343/determine-video-bitrate-using-ffmpeg

## torrents
   1337x
   1337x mirror
   KickassTorrents
   Torrent Bay
   fmovies

## easy p2p file transfer 
   ::: more at https://www.sharedrop.io/

## link to directory / alias path
   ln -s /home/{path} name
   ::: more at https://stackoverflow.com/questions/17958567/how-to-make-an-alias-for-a-long-path
   ::: more at https://www.man7.org/linux/man-pages/man1/ln.1.html

## what does "2>&1" mean?
   it redirects stderr to stdout. both 1 and 2 are file descriptors (0: stdin 1: stdout 2: stderr)
   the same way that { echo test > file.txt } -> { 2>&1 } // note no whitespaces
   also { echo test > file.txt } is equivalent to { echo test 1 > file.txt }
   so { &1 } just redirects to another file descriptor instead of a common file.
   ::: more at

## minecraft coordinates [c/ filipe]
   portal nether : -60 60 -30
   forteleza nova nether -230 68 -305
   base -420 69 -154
   vila em planicie -123 88 -718
   fortaleza nether -185 81 494
   spectro fim principal -991 57 323
   subida mineracao netherite -24 15 -22

## counting chars of a file with grep and wc
   echo "total chars $(cat file.txt)" | grep -o "." | wc -l
   "-o" means grep will return just the found char instead of the entire line as usual
   "." searches for all chars. wildcard

## list only directories on linux
    ls -d */
    ls -l | grep '^d'
    find . -maxdepth 1 -type d
    echo */
    tree -d -L 1

## encrypt a file using zip [with password]
    zip --password prefered_password archive_file.zip filename1 filename2
    unzip archive_file.zip

## minecraft tutorials youtube channels
    shulkercraft

## bootable usb stick on linux | image writer method ||> dd utility
    lsblk
    sudo dd bs=4M if=Downloads/ubuntu-19.04-desktop-amd64.iso of=/dev/sdb conv=fdatasync status=progress
    ::: more at https://www.howtogeek.com/414574/how-to-burn-an-iso-file-to-a-usb-drive-in-linux/

## format C file    
    clang-format file.c f_file.c

## duckduckgo search flags
    !w      wikipedia
    !g      google
    !wt     wiktionary
    !wtpt   wikcionario
    !gh     github

## format usb stick using mkfs
        lsblk
        sudo umount /dev/sdy1
    # format using fat32
        sudo mkfs.vfat -F 32 /dev/sdy1
    # set a file system label !! may need -I depending on the current partitions on your drive
        sudo mkfs.vfat -F 32 -n 'name_for_your_pendrive' /dev/sdy1
    ::: more at https://askubuntu.com/questions/22381/how-to-format-a-usb-flash-drive
## list mounted disks on sytems
    # can be combined with "| grep sdx"
        cat /proc/mounts
        cat /proc/self/mounts

## using latex
    package on arch: texlive-most
    * simple example:
    `
        \documentclass{article}
        \begin{document}
        Hello, World!
        \end{document}
    `
    pdflatex helloworld.tex

## comando sync
    assegura/compara se os dados de X operação presentes na memória estão devidamente escritos no disco
    ::: more at https://unix.stackexchange.com/questions/706359/when-and-why-should-i-sync-a-file-in-linux
    ::: more at https://www.gnu.org/software/coreutils/manual/html_node/sync-invocation.html#sync-invocation

## mic configuration on discord web linux
    sensibilidade de entrada : -31dB
    cancelamento de eco : yes
    supressão de ruído : padrão
    controle automático do microfone : yes
    
## clean "/var/cache" directory
    # Just to share a magic command to know where all your disk space goes:
        sudo du -hsx /* | sort -rh | head -n 40
    # Then you can start again from another folder:
        sudo du -hsx /home/* | sort -rh | head -n 35
    ::: more at https://askubuntu.com/questions/266825/what-do-i-do-when-my-root-filesystem-is-full
    # From the same guy above : LINUX CHEAT SHEET
    ::: more at https://mickael.kerjean.me/2016/05/02/linux-cheat-sheet/
    # Cleaning package cache in /var/cache/pacman/pkg
    ::: more at https://wiki.archlinux.org/title/Pacman#Cleaning_the_package_cache

## more about postgresql and pgAdmin
    # set up postgresql on arch linux 
    ::: more at https://wiki.archlinux.org/title/PostgreSQL
    # start up when everything in done
        systemctl status postgresql || systemctl start postgresql
        pgadmin4

## adjust time and date on linux
    # list info about current time and date settings
        timedatectl
    # found out if time syncronization is on in case of unsync clock
        sudo systemctl start systemd-timesyncd.service
    # start the service
        sudo systemctl start systemd-timesyncd.service
    # brasilia
        timedatectl set-timezone Brazil/East

## database schema from pgadmin / postgresql    
    pg_dump -U aplicacao_user --no-owner --no-acl aplicacao_db > aplicacao_db.sql

## search/highlight multiple words in vim 
    $ /search1\|search2

## use virtual env for python projects
    query at duckduckgo: "how to install libraries using virtual environments from python"
    more at docs ::: https://packaging.python.org/en/latest/guides/installing-using-pip-and-virtual-environments/#installing-packages-using-pip-and-virtual-environments

## connect android device to a arch distro
    First enable MTP support by installing :
        $ sudo pacman -S mtpfs
    To auto mount it (device), we need to install a package with :
        $ sudo pacman -S gvfs-mtp
    To enable PTP, we need to install a package with :
        $ sudo pacman -Sy gvfs-gphoto2
        $ reboot 
    Now, your File Manager should list your device and you can access the Device files easily !
    last time i did it using filesystem: thunar
    more ate ::: https://www.linuxfordevices.com/tutorials/linux/connect-android-to-arch-via-usb

## DOOM emacs
    But before you doom yourself, here are some things you should know:

    1. Don't forget to run 'doom sync', then restart Emacs, after modifying init.el
       or packages.el in ~/.config/doom.

       This command ensures needed packages are installed, orphaned packages are
       removed, and your autoloads/cache files are up to date. When in doubt, run
       'doom sync'!

    2. If something goes wrong, run `doom doctor`. It diagnoses common issues with
       your environment and setup, and may offer clues about what is wrong.

    3. Use 'doom upgrade' to update Doom. Doing it any other way will require
       additional steps. Run 'doom help upgrade' to understand those extra steps.

    4. Access Doom's documentation from within Emacs via 'SPC h d h' or 'C-h d h'
       (or 'M-x doom/help')

    Have fun!

    ✓ Finished in 4m 41s

## ABRIR PELO SOFTWARE PADRÃO 
    $ xdg-open filename
