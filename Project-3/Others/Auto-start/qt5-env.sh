#!/bin/sh

export QT_QPA_EGLFS_KMS_CONFIG=/etc/kms.conf
export QT_QPA_EGLFS_INTEGRATION=eglfs_kms
export QT_QPA_PLATFORM=eglfs
export QT_QPA_EGLFS_KMS_ATOMIC=1
export XDG_RUNTIME_DIR=/run/user/0
export $(dbus-launch)
ip link set can0 up type can bitrate 500000

# cd /usr/bin
# IpcClient & yoctoIVI &
# if python3 -c 'import pkgutil; exit(not pkgutil.find_loader("piracer"))'; then
#     cd /usr/bin
#     python3 rc_example.py 
# else
#     while :
#     do
#         echo -e "GET http://google.com HTTP/1.0\n\n" | nc google.com 80 > /dev/null 2>&1
  
#         if [ $? -eq 0 ]; then
#           pip3 install piracer-py
#           reboot
#           break
#         else
#           echo "Offline"
#         fi
#     done
#     cd /usr/bin
#     python3 rc_example.py 
# fi

# /usr/bin/yoctoIVI & /usr/bin/IpcClient