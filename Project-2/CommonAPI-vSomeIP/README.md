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

A service which instantiates the interface `HelloWorld` provides the function `sayHello` which can be called

```bash
nano HelloWorld.fidl
```

- HelloWorld.fidl
    
    ```bash
    package commonapi
    
    interface HelloWorld {
      version {major 1 minor 0}
      method sayHello {
        in {
          String name
        }
        out {
          String message
        }
      }
    }
    ```
    

```bash
nano HelloWorld.fdepl
```

- HelloWorld.fdepl
    
    ```bash
    import "platform:/plugin/org.genivi.commonapi.someip/deployment/CommonAPI-SOMEIP_deployment_spec.fdepl"
    import "HelloWorld.fidl"
    
    define org.genivi.commonapi.someip.deployment for interface commonapi.HelloWorld {
            SomeIpServiceID = 4660
    
            method sayHello {
                    SomeIpMethodID = 123
            }
    }
    
    define org.genivi.commonapi.someip.deployment for provider MyService {
            instance commonapi.HelloWorld {
                    InstanceId = "test"
                    SomeIpInstanceID = 22136
            }
    }
    ```
    

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

```bash
nano HelloWorldClient.cpp
```

- HelloWorldClient.cpp
    
    ```bash
    // HelloWorldClient.cpp
    #include <iostream>
    #include <string>
    #include <unistd.h>
    #include <CommonAPI/CommonAPI.hpp>
    #include <v1/commonapi/HelloWorldProxy.hpp>
    
    using namespace v1_0::commonapi;
    
    int main() {
        std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
        std::shared_ptr<HelloWorldProxy<>> myProxy =
        	runtime->buildProxy<HelloWorldProxy>("local", "test");
    
        std::cout << "Checking availability!" << std::endl;
        while (!myProxy->isAvailable())
            usleep(10);
        std::cout << "Available..." << std::endl;
    
        CommonAPI::CallStatus callStatus;
        std::string returnMessage;
        myProxy->sayHello("Bob", callStatus, returnMessage);
        std::cout << "Got message: '" << returnMessage << "'\n";
        return 0;
    }
    ```
    

```bash
nano HelloWorldService.cpp
```

- HelloWorldService.cpp
    
    ```bash
    // HelloWorldService.cpp
    #include <iostream>
    #include <thread>
    #include <CommonAPI/CommonAPI.hpp>
    #include "HelloWorldStubImpl.hpp"
    
    using namespace std;
    
    int main() {
        std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
        std::shared_ptr<HelloWorldStubImpl> myService =
        	std::make_shared<HelloWorldStubImpl>();
        runtime->registerService("local", "test", myService);
        std::cout << "Successfully Registered Service!" << std::endl;
    
        while (true) {
            std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(30));
        }
        return 0;
     }
    ```
    

```bash
nano HelloWorldStubImpl.hpp
```

- HelloWorldStubImpl.hpp
    
    ```bash
    // HelloWorldStubImpl.hpp
    #ifndef HELLOWORLDSTUBIMPL_H_
    #define HELLOWORLDSTUBIMPL_H_
    #include <CommonAPI/CommonAPI.hpp>
    #include <v1/commonapi/HelloWorldStubDefault.hpp>
    
    class HelloWorldStubImpl: public v1_0::commonapi::HelloWorldStubDefault {
    public:
        HelloWorldStubImpl();
        virtual ~HelloWorldStubImpl();
        virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client,
        	std::string _name, sayHelloReply_t _return);
    };
    #endif /* HELLOWORLDSTUBIMPL_H_ */
    ```
    

```bash
nano HelloWorldStubImpl.cpp
```

- HelloWorldStubImpl.cpp
    
    ```bash
    // HelloWorldStubImpl.cpp
    #include "HelloWorldStubImpl.hpp"
    
    HelloWorldStubImpl::HelloWorldStubImpl() { }
    HelloWorldStubImpl::~HelloWorldStubImpl() { }
    
    void HelloWorldStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client,
    	std::string _name, sayHelloReply_t _reply) {
    	    std::stringstream messageStream;
    	    messageStream << "Hello " << _name << "!";
    	    std::cout << "sayHello('" << _name << "'): '" << messageStream.str() << "'\n";
    
        _reply(messageStream.str());
    };
    ```
    
<br/>

## Step 8: Build and run

```bash
cd ~/build-commonapi/project
nano CMakeLists.txt
```

- CMakeLists.txt
    
    ```bash
    cmake_minimum_required(VERSION 2.8)
    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
    include_directories(
        src-gen
        ~/build-commonapi/capicxx-core-runtime/include
        ~/build-commonapi/capicxx-someip-runtime/include
        ~/build-commonapi/vsomeip/interface
    )
    link_directories(
        ~/build-commonapi/capicxx-core-runtime/build
        ~/build-commonapi/capicxx-someip-runtime/build
        ~/build-commonapi/vsomeip/build
    )
    add_executable(HelloWorldClient
            src/HelloWorldClient.cpp
            src-gen/v1/commonapi/HelloWorldSomeIPProxy.cpp
            src-gen/v1/commonapi/HelloWorldSomeIPDeployment.cpp
    )
    target_link_libraries(HelloWorldClient CommonAPI CommonAPI-SomeIP vsomeip)
    add_executable(HelloWorldService
            src/HelloWorldService.cpp
            src/HelloWorldStubImpl.cpp
            src-gen/v1/commonapi/HelloWorldSomeIPStubAdapter.cpp
            src-gen/v1/commonapi/HelloWorldStubDefault.cpp
            src-gen/v1/commonapi/HelloWorldSomeIPDeployment.cpp
    )
    target_link_libraries(HelloWorldService CommonAPI CommonAPI-SomeIP vsomeip)
    ```
    

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