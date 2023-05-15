#version 430

uniform int coloring;
out vec4 color;

void main(void)
{
	if (coloring == 0){
		color = vec4(1.0, 0.0, 0.0, 1.0);
	}
	else if(coloring == 1){
		color = vec4(0.0, 0.0, 1.0, 1.0);
	}
	else {
		color = vec4(0.0, 1.0, 0.0, 1.0);
	}
}