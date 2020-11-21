

attribute vec2 a_Position;
attribute vec2 a_UVCoord; // Input from VBO in C++

uniform vec2 u_Position;
uniform vec2 u_UVScale; 
uniform vec2 u_UVOffset;

varying vec2 v_UVCoord; // Output to frag shader

void main()
{
    vec2 pos = a_Position;

    // Scale and offset the object
    pos *= 1;

    // Rotate
    pos += u_Position;

    // Offset for camera position
    pos -= vec2(5,5);

    // Divide to fit in clip space
    pos /= vec2(5,5);

    v_UVCoord = a_UVCoord * u_UVScale + u_UVOffset;
   
    gl_Position = vec4( pos, 0, 1 );
}