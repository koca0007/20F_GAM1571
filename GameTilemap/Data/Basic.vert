

attribute vec2 a_Position;
attribute vec2 a_UVCoord; // Input from VBO in C++

uniform vec2 u_Position;

varying vec2 v_UVCoord; // Output to frag shader

void main()
{
    vec2 pos = a_Position;
    vec2 offset = u_Position;

    pos /= 5.0;
    pos -= 1.0;


    offset /= 5.0;
    pos += offset;

    v_UVCoord = a_UVCoord;
   
    gl_Position = vec4( pos, 0, 1 );
}