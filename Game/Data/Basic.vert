

attribute vec2 a_Position;

uniform vec2 u_Position;

void main()
{
    vec2 aPosition = a_Position;
    vec2 uPosition = u_Position;

    aPosition /= 5;
    uPosition = 10;

    vec2 pos = aPosition + u_Position;



    gl_Position = vec4( pos, 0, 1 );
}