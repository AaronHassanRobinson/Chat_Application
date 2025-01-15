if [ ! -d "Server/Build" ]; then 
    echo "Making server build dir..."
    mkdir Server/Build
else 
    echo "Server build dir already exists."
fi
gcc -g Server/Server.c -o Server/Build/Server