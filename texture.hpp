#pragma once


// Load a .BMP file using our custom loader
GLuint loadBMP_custom(const char *imagepath);

// Load a .DDS file using GLFW's own loader
GLuint loadDDS(const char *imagepath);
