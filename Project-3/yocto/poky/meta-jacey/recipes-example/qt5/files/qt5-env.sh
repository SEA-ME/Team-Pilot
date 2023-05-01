#!/bin/sh

#export QT_LOGGING_RULES=qt.qpa.*=true # Optional for logging
export QT_QPA_EGLFS_KMS_CONFIG=/etc/kms.conf
export QT_QPA_EGLFS_INTEGRATION=eglfs_kms
# export QT_QPA_EGLFS_INTEGRATION=eglfs_kms # kms doesn't work on boot2qt but eglfs_kms
export QT_QPA_PLATFORM=eglfs
export QT_QPA_EGLFS_KMS_ATOMIC=1
# export QT_DEBUG_PLUGINS=1
export XDG_RUNTIME_DIR=/run/user/0
export $(dbus-launch)
ip link set can0 up type can bitrate 500000
/usr/bin/quickIC1 & /usr/bin/IpcClient
