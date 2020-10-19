

attribute vec2 a_Position;
uniform vec2 u_Position;

void main()
{
    vec2 pos = a_Position;
    vec2 offset = u_Position;

    pos /= 5.0;
    pos -= 1.0;

    offset /= 5.0;
    pos += offset;
   

    gl_Position = vec4( pos, 0, 1 );
}