cmake  --build build/Debug
scp build/Debug/f4learn.elf zwb@192.168.10.6:/home/zwb/ 
ssh zwb@192.168.10.6 /home/zwb/flash.sh