# UI Module
## How-To-Use
* Run the GenerateProject file associated with the OS in the Scripts folder. This will generate project structure using premake.
* After generating project for linux based OS enviroments, run the RunProject file associated with the OS. This will authorize file and run it.
## Or run with Docker
* Use this command to run with docker

Install these libraries
```sudo apt-get update```
```sudo apt-get install xserver-xorg-core xinit xterm```

Install docker
```
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh
sudo usermod -aG docker pi
```

Start xserver (on host machine)
```startx```

Change following line with current system cookie 

```RUN xauth add raspberrypi/unix:0  MIT-MAGIC-COOKIE-1 7a8a3650df58de6c6f6b9dfc2d4f623e```

(get current system cookie with ```xauth list```)

Build
```docker build -t ui-module .```

Run
```docker run -i -t --net=host -e DISPLAY -v /tmp/.X11-unix ui-module```

### Windows
* Just double click for running GenerateProjectWindows.bat file. This will generate all the project for Visual studio 2022.
* After that open the solution and build it.
### ARM
* Embedded devices need spesific libraries to get graphic libraries. InstallNecesarryLibrariesArm.sh will install all the necessary libraries for you.
* After that generate makefile and run this file with GenerateProjectArm.sh
* After making project just run RunProjectArm.sh file for running the project quickly.
* For doing all of that in command line, go to script directory in command line and run scripts below;
```
sudo su
bash InstallNecesarryLibrariesArm.sh
bash GenerateProjectArm.sh
bash RunProjectArm.sh
```

## Folder Structure
### UiApp
* UiApp is our end-point module so that folder contains end-point module files.
* src folder contains .h and .cpp files.
* image folder contains images that used in main app.

### UiEngine
* UiEngine is out engine module for Ui system.
* vendor folder contains codes written by others. 
