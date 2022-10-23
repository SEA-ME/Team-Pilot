# CommonAPI vSomeIP Setup (RPi 4B)

## Contents
- [Step 1: Install OpenJDK Java 8 on Raspberry Pi](#step-1-install-openjdk-java-8-on-raspberry-pi)
- [Step 2: Install Boost.Asio library](#step-2-install-boostasio-library)
- [Step 3: Build the CommonAPI Runtime Library](#step-3-build-the-commonapi-runtime-library)
- [Step 4: Build the vsomeip Library](#step-4-build-the-vsomeip-library)
- [Step 5: Build the CommonAPI SOME/IP Runtime Library](#step-5-build-the-commonapi-someip-runtime-library)
- [Step 6: Write the Franca file and generate code](#step-6-write-the-franca-file-and-generate-code)

---

<br/>

## Reference
- [CommonAPI SomeIP in 10-minutes](https://github.com/COVESA/capicxx-someip-tools/wiki/CommonAPI-C---SomeIP-in-10-minutes)
- [How to Install Java on Raspberry Pi](https://phoenixnap.com/kb/install-java-raspberry-pi#ftoc-heading-4)
- [How to install latest Boost library on Raspberry Pi](http://osdevlab.blogspot.com/2016/02/how-to-install-latest-boost-library-on.html)

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

```bash
sudo apt-get install libboost-all-dev
```

Check version of boost (1.55 - 1.65)

```bash
dpkg -s libboost-dev | grep 'Version'
```

If your boost version is bigger than 1.65, you should downgrade version

![Untitled](https://user-images.githubusercontent.com/111988634/197358975-657a5dbb-ce06-459a-ac90-bd04078a9642.png)


Download and Extract file

```bash
cd ~ && mkdir boost && cd boost
wget -O boost_1_55_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.55.0/boost_1_55_0.tar.gz/download
tar xzvf boost_1_55_0.tar.gz
cd boost_1_55_0/
```

```bash
sudo apt-get update
sudo apt-get install build-essential g++ python-dev autotools-dev libicu-dev libbz2-dev
```

If you want to use Boost.Asio only, add requirements by `--with` to reduce build time

```bash
./bootstrap.sh --prefix=/usr/local --with-libraries=date_time,filesystem,iostreams,math,regex,serialization,signals,system,thread,timer
```

```bash
sudo ./b2 install
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
cmake -DGTEST_ROOT=/usr/src/gtest -DENABLE_SIGNAL_HANDLING=1 -DDIAGNOSIS_ADDRESS=0x10 ..
make
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