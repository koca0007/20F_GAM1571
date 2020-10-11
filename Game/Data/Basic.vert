

attribute vec2 a_Position;

uniform vec2 u_Position;

void main()
{
    vec2 pos = a_Position;

    pos *= 1;
    pos += u_Position;

    // Transform from 0->10 space into -1->1 space:
    pos /= 5.0;
    pos -= 1.0;

    gl_Position = vec4( pos, 0, 1 );
}