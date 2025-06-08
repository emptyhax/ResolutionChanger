#!/bin/bash

 
EXECUTABLE="resolutionChanger"

COMPILER="g++"

FLAGS="-Wall -Wextra -std=c++17 -O2"
 
SOURCE="main.cpp"

 
echo "🔨 Compilando $SOURCE..."
$COMPILER $FLAGS $SOURCE -o $EXECUTABLE

 
if [ $? -eq 0 ]; then
    echo "✅ Compilação concluída! Executando $EXECUTABLE..."
    ./$EXECUTABLE
else
    echo "❌ Erro na compilação. Verifique o código."
    exit 1
fi