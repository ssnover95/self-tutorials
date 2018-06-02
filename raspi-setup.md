# Setting Up RPi3 on Ubuntu 18.04
A short series of directions on common setup for headless Raspbian. Assumes: Host PC is running Ubuntu 18.04, Pi is hardware version 3, and you're installing Raspbian.

## Flash SD Card
1. Download Raspbian Stretch zip and extract  *.img file.
2. Plug in SD card in adapter and run `df -h` to find device path. Mine was `/dev/sdc`.
3. Run `umount /dev/sdc*` to remove the chance of files being written or read from the card.
4. Run `sudo dd bs=4M status=progress if=<raspbian>.img of=/dev/sdc`

## Setting up SSH
1. Unplug and plug back in SD card.
2. Add `ssh` file to `boot` partition. `touch /media/<user>/boot/ssh`

## Making a connection
1. Plug in SD card, ethernet cable to Pi and PC, and power up Pi.
2. Run `nm-connection-manager`
3. Under IPV4 tab, click the dropdown and select "Share connection with other computers."
4. Run `ifconfig` to get the IP address of the ethernet connection, mine was `10.42.0.1`
5. Run `nmap -n -sP 10.42.0.255/24` which should return the IP address of the Pi.
6. Run `ssh pi@<ip-address>`. Password will be `raspberry` by default, make sure to change it with `passwd`

## Add SSH Keys
1. Run `ssh-keygen`. Call the file something like `pi.id_rsa`.
2. Possibly may need to make a `.ssh` directory under the home directory. On Pi terminal: `mkdir ~/.ssh`. 
3. Run `ssh-copy-id -i <path-to-new-pi.id_rsa.pub> pi@<ip-address>`