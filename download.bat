cmake  --build build/Debug
scp -P 17708 build/Debug/f4learn.elf zwb@frp-now.com:/home/zwb/ 
ssh -p 17708 zwb@frp-now.com /home/zwb/flash.sh