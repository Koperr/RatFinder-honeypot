cd build
make
cd ..

OS=$(uname)

echo "Running on: ["$OS"] OS"

if [ "$OS" = "Darwin" ]; then
    # macOS
    EXEC_PATH="bin/Darwin/Debug"
elif [ "$OS" = "Linux" ]; then
    # Linux
    EXEC_PATH="bin/Linux/Debug"
else
    echo "Unsupported OS: $OS"
    exit 1
fi

cd $EXEC_PATH
./RatFinder
cd ../..
