#!/bin/bash

# Check if the build directory already exists
if [ ! -d "build" ]; then
  echo "Creating build directory..."
  mkdir build
fi

# Run CMake to configure the project
echo "Configuring the project with CMake..."
cmake -S . -B build

# Check if the configuration was successful
if [ $? -eq 0 ]; then
  echo "CMake configuration successful."
  
  # Build the project
  echo "Building the project..."
  cmake --build build
  
  # Check if the build was successful
  if [ $? -eq 0 ]; then
    echo "Build successful!"
    
     # Run the executable
    echo "Running the executable..."
    ./build/XanderOne
  else
    echo "Build failed."
    exit 1
  fi

else
  echo "CMake configuration failed."
  exit 1
fi