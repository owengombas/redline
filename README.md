# CPP_FilRouge_ISCc

## Mise en place de l'environnement

### Windows
1. [Installez MinGW](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)
   
2. Vérifiez que la commande `g++` fonctionne sur votre terminal Windows
   ```
    PS C:\> g++
    g++.exe: fatal error: no input files
    compilation terminated.
   ```

4. Si vous voulez que votre terminal Windows sois en UTF-8, exécuter le fichier `windows-set-utf8.bat` (évite les problèmes d'affichage)
   ```
    PS C:\> .\windows-set-utf8.bat
   ```

3. Allez à la racine du projet avec un terminal Windows et exécutez le fichier `windows.bat` qui compile le programme via `g++` et le lance
   ```
    PS C:\redline> .\windows.bat
    C:\redline>del main.exe
    C:\redline>g++ -g main.cpp sources/*.cpp -o main.exe -std=c++17
    ...
   ```

5. Le programme devrait se lancer normalement, vous devriez pouvoir naviguer dans les menus.  
   Si ce n'est pas le cas, il y'a dû avoir un problème de configuration. Veuillez alors me contacter par mail ou Discord

### MacOS / Linux
1. Vous pouvez simplement exécutez le script `unix.sh` qui va faire un `make clean` et `make` puis lancer le projet
   ```sh
   $ sh unix.sh
   ```

## Cours
[Le cours est disponible sur CyberLearn (HE-Arc)](https://cyberlearn.hes-so.ch/course/view.php?id=15188)

## Résumés
Tous les résumé du cours se trouvent [ici](https://github.com/OwenCalvin/abstracts/tree/main/cpp/)
