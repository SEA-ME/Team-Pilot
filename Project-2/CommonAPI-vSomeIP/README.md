# CommonAPI vSomeIP Setup (RPi 4B)

## Contents
- [Step 1: Install OpenJDK Java 8 on Raspberry Pi](#step-1-install-openjdk-java-8-on-raspberry-pi)
- [Step 2: Install Boost.Asio library](#step-2-install-boostasio-library)
- [Step 3: Build the CommonAPI Runtime Library](#step-3-build-the-commonapi-runtime-library)
- [Step 4: Build the vsomeip Library](#step-4-build-the-vsomeip-library)
- [Step 5: Build the CommonAPI SOME/IP Runtime Library](#step-5-build-the-commonapi-someip-runtime-library)
- [Step 6: Write the Franca file and generate code](#step-6-write-the-franca-file-and-generate-code)
- [Step 7: Write the client and the service application](#step-7-write-the-client-and-the-service-application)
- [Step 8: Build and run](#step-8-build-and-run)

---

<br/>

## Reference
- [CommonAPI SomeIP in 10-minutes](https://github.com/COVESA/capicxx-someip-tools/wiki/CommonAPI-C---SomeIP-in-10-minutes)
- [How to Install Java on Raspberry Pi](https://phoenixnap.com/kb/install-java-raspberry-pi#ftoc-heading-4)
- [How to install latest Boost library on Raspberry Pi](http://osdevlab.blogspot.com/2016/02/how-to-install-latest-boost-library-on.html)
- [CommonAPI C++ User Guide](https://usermanual.wiki/Document/CommonAPICppUserGuide.113855339.pdf)
---

<br/>

## Step 1: Install OpenJDK Java 8 on Raspberry Pi
- **OpenJDK** – An open-source Java environment, licensed under the GNU General Public License.
- **Oracle Java** – A paid service that includes support options and licensing. (most are not compatible with Raspberry Pi)
JRE: Java Runtime Environment (for running Java applications)
```bash
sudo apt update
sudo apt install openjdk-8-jdk
```

You can check installation

```bash
java --version
```

If you have installed both OpenJDK 8 and 11, your default version will OpenJDK 11.
![Untitled](https://user-images.githubusercontent.com/111988634/197338445-baf28b79-91c1-4ca6-9c7b-ce712df4a6f3.png)
To manually set a Java version, start by running the following command

```bash
sudo update-alternatives --config java
```

Select number and set OpenJDK 8 as the system default
![Untitled (1)](https://user-images.githubusercontent.com/111988634/197338474-65925e4a-955d-4090-9a57-9f0a77b68ada.png)
```bash
java -version
```
![Untitled (2)](https://user-images.githubusercontent.com/111988634/197338489-1a2453f9-5618-4ef7-95f1-0b1ab567c4c1.png)

<br/>

## Step 2: Install Boost.Asio library
Install Boost-dev
```bash
sudo apt-get install libboost-all-dev
```
```bash
sudo apt-get update
sudo apt-get install build-essential g++ python3-dev autotools-dev libicu-dev libbz2-dev
sudo apt-get install cmake libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev
```

Download and Extract file

```bash
cd ~ && mkdir boost && cd boost
wget -O boost_1_55_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.55.0/boost_1_55_0.tar.gz/download
tar xzvf boost_1_55_0.tar.gz
cd boost_1_55_0/
```


If you want to use Boost.Asio only, add requirements by `--with` to reduce build time

```bash
./bootstrap.sh --prefix=/usr/local --with-libraries=date_time,filesystem,iostreams,math,regex,serialization,signals,system,thread,timer
```

```bash
sudo ./b2 -j$(nproc) install
```

Check your boost version

```cpp
cat /usr/local/include/boost/version.hpp | grep "BOOST_LIB_VERSION"
```

![Untitled (1)](https://user-images.githubusercontent.com/111988634/197358974-475d6053-438b-476c-8435-dacb2e98bd18.png)

<br/>

## Step 3: Build the CommonAPI Runtime Library

Make working directory. In my case `build-commonapi`

```bash
cd ~
mkdir build-commonapi && cd build-commonapi
```

Start with fetching the source code of CommonAPI:

```bash
git clone https://github.com/GENIVI/capicxx-core-runtime.git
cd capicxx-core-runtime/
git checkout 3.1.12.4
mkdir build
cd build
cmake ..
make
```

Result:

```bash
[100%] Linking C shared library libCommonAPI.so
[100%] Built target CommonAPI
```

<br/>

## Step 4: Build the vsomeip Library

To build the documentation asciidoc, you need followings

```bash
sudo apt-get install asciidoc source-highlight doxygen graphviz libgtest-dev

# Only for Ubuntu
pip3 install asciido
make doc
```

Before download SOME/IP Runtime library, you should download vsomeip. Because CommonAPI C++ SOME/IP need vsomeip.

```bash
git clone https://github.com/COVESA/vsomeip.git
cd vsomeip
git checkout 2.14.16
mkdir build
cd build
cmake -DENABLE_SIGNAL_HANDLING=1 -DDIAGNOSIS_ADDRESS=0x10 ..
make
sudo make install
```

![Untitled (2)](https://user-images.githubusercontent.com/111988634/197358973-be132356-d7e0-4d26-b97d-a6d14c48c0a6.png)

<br/>

## Step 5: Build the CommonAPI SOME/IP Runtime Library

Download CommonAPI SOME/IP Runtime Library and change version

```bash
git clone https://github.com/GENIVI/capicxx-someip-runtime.git
cd capicxx-someip-runtime/
git checkout 3.1.12.12
mkdir build
cd build
cmake -DUSE_INSTALLED_COMMONAPI=OFF ..
make
```

![Untitled (3)](https://user-images.githubusercontent.com/111988634/197358972-14c36a99-5dc8-42a3-ba13-25f5f7f1e685.png)

<br/>

## Step 6: Write the Franca file and generate code

Unfortunately, code generator [doesn’t support arm architecture.]((https://github.com/COVESA/capicxx-core-tools/issues/19)) So if you want to use this generator, I recommend that you use the code generator on your laptop and then download the generated code via Git.

<br/>

`PC`

Create commonapi project directory and open Franca IDL

```bash
cd ~
mkdir project
cd project
mkdir fidl
cd fidl
```

A service which instantiates the interface `HelloWorld` provides the function `sayHello` which can be called. Write fidl and fdepl file in fidl directory.

- ### [HelloWorld.fidl](project/fidl/HelloWorld.fidl)

- ### [HelloWorld.fdepl](project/fidl/HelloWorld.fdepl)

Download code generator 3.1.12.4

```bash
cd ~/project
mkdir cgen && cd cgen
wget https://github.com/COVESA/capicxx-core-tools/releases/download/3.1.12.4/commonapi-generator.zip
unzip commonapi-generator.zip -d commonapi-generator
cd commonapi-generator
chmod +x commonapi-generator-linux-x86_64
```

Download someip code generator 3.1.12.2

```bash
cd ~/project/cgen
wget https://github.com/COVESA/capicxx-someip-tools/releases/download/3.1.12.2/commonapi_someip_generator.zip
unzip commonapi_someip_generator.zip -d commonapi_someip_generator
cd commonapi-someip-generator/
chmod +x commonapi-someip-generator-linux-x86_64
```

Run generator

```bash
cd ~/project
./cgen/commonapi-generator/commonapi-generator-linux-x86_64 -sk ./fidl/HelloWorld.fidl
./cgen/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64 ./fidl/HelloWorld.fdepl
```

Now, send the generated code to Raspberry pi using rsync command line

```bash
cd ~/project
rsync -avz src-gen <user-name>@<IP-address>:<project-directory>
```

In my case

```bash
rsync -avz src-gen moon@192.168.0.105:/home/build-commonapi/project
```

<br/>

## Step 7: Write the client and the service application

<br/>

`Raspberry Pi`

```bash
cd ~/build-commonapi/project
mkdir src && cd src
```

Make 4 files in src directory

- ### [HelloWorldClient.cpp](project/src/HelloWorldClient.cpp)

- ### [HelloWorldService.cpp](project/src/HelloWorldService.cpp)

- ### [HelloWorldStubImpl.hpp](project/src/HelloWorldStubImpl.hpp)
    
- ### [HelloWorldStubImpl.cpp](project/src/HelloWorldStubImpl.cpp)

    
<br/>

## Step 8: Build and run

```bash
cd ~/build-commonapi/project
```
Write CMakeLists.txt on proejct directory

 - ### [CMakeLists.txt](project/CMakeLists.txt)
 
Build and run

```bash
mkdir build
cd build
cmake ..
make
```

```bash
./HelloWorldService
./HelloWorldClient
```