# camera

1 . Modify local.conf

```jsx
cd ~/yocto/poky/build/conf
vim local.conf
```

Add following lines:

```jsx
# For camera 
PACKAGECONFIG:append = " gstreamer"
LICENSE_FLAGS_ACCEPTED="commercial"

VIDEO_CAMERA = "1"
```

2 .  Modify my custom image

```jsx
cd ~/yocto/poky/meta-mylayer/recipes-core/images
vim qt-api-test-image
```

Add following lines:

```jsx
IMAGE_INSTALL:append = " \ 
    gstreamer1.0 \
    gstreamer1.0-libav \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    libcamera \
    kernel-modules \
"
```

3. Modify rpi-config

```jsx
cd ~/yocto/poky/meta-mylayer/recipes-bsp/bootfiles
vim rpi-config_git.bbappend
```

Add following lines:

```jsx
do_deploy:append() {
    echo "start_x=1" >> ${DEPLOYDIR}/bootfiles/config.txt
    echo "gpu_mem=128" >> ${DEPLOYDIR}/bootfiles/config.txt
}
```

4. BitBake

- Trouble shooting
    
    If you got a error message
    
    ```jsx
    | Error: could not load cache
    | WARNING: exit code 1 from a shell command.
    ERROR: Task (/home/seame-two/yocto/poky/meta-openembedded/meta-oe/recipes-support/opencv/opencv_4.5.5.bb:do_install) failed with exit code '1'
    ```
    
    Do like this
    
    ```jsx
    bitbake opencv -c cleansstate
    bitbake opencv -c complie
    ```
    
    ```jsx
    bitbake opencv
    ```
    

5. Checking camera connection

After booing, 

```jsx
vcgencmd get_camera
```

The following results show that the camera is well connected.

`supported=1 , detected=1`