## Add startx to rc.local file so it run on startup.
sudo nano /etc/rc.local

startx &
sleep 5

## Add .xinitrc file to root file to run on start of xterm session
Create .xinitrc file on root copy next line inside

sudo chmod +x .xinitrc

#!/bin/sh
cd /home/pi/ui-module/scripts
xterm -hold -e "bash RunProjectArm.sh"
