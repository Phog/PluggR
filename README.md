How to build and run:

1) Install the web application (ServR) by following the instructions
   at http://cs.helsinki.fi/u/phedman/ServR.zip

2) Build OpenCV from source using cmake:
	i) Install cmake
	ii) Clone the OpenCV source code:
		$ cd [OPENCV-PROJECT-DIRECTORY]
		$ git clone https://github.com/Itseez/opencv.git
	iii) Checkout the 2.4 branch
		$ git checkout 2.4
	iv) Build and install OpenCV using the the instructions at:
	http://docs.opencv.org/doc/tutorials/introduction/linux_install/linux_install.html

3) Install the following packages:
	build-essential, swig, php5-dev

4) Define the required environment variables
	$ export WEB_ROOT="[PATH-TO-SERVR-FOLDER]/www"
	$ export PHP_PLUGIN_FOLDER=[PATH-TO-PHP-PLUGINS]
	(PHP_PLUGIN_FOLDER is usually /usr/lib/php5/SOME_DATE/)

5) Compile and run the project:
	$ cd [PluggR-DIRECTORY]
	$ make release
	$ make install_release # needs sudo rights

Note: This has only been tested on Ubuntu 12.04.3 LTS 64 bit.
