# Cletyxo
Open-source userfriendly operating system.


## Installation

There is no stable release candidate for Cletyxo at the moment.

## Basic Documentation

Filetypes:
    - **.rck files**  These files, called Rocketfiles are the executables of Cletyxo.


Starter applications:
    - **Catapult**: This program allows you to launch any .exe from windows on your cletyxo machine.
    - **Notepad**: A basic text editor


## How to get started
[More comming soon :)]
Install it, setup the kernel by going into kernel and using the "make setup" command, build the gnu-efi by going into it and doing "make setup"
Compile the kernel using "make kernel" and then "make buildimg" to boot it.
You can also just use "make pfb"
[Linux only]
Use "make boot" in kernel to compile, link, make the buildimg and then boot it using qemu.