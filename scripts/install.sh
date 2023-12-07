echo "Welcome to the installation script of the project"
echo "This script will install all the dependencies needed to run the project"
echo "It will install the following dependencies:"
echo "1. CMake"
echo "3. Valgrind"
echo "5. GDB"
read -p "do you want to continue? (y/n)" answer
if [ "$answer" != "y" ]; then
    echo "Installation aborted"
    exit 1
fi
sudo apt update
sudo apt install build-essential
sudo apt-get install cmake
sudo apt-get install valgrind
mkdir export