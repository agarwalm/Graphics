#include <GLUT/glut.h>
#include "Animation.h"
#include <stdlib.h>

Animation::Animation()
{
    static GLenum singleStep = GL_FALSE;
    static GLenum spinMode = GL_TRUE;
    static float AnimateIncrement = 24.0;
}

 void KeyPressFunc( unsigned char Key, int x, int y )
{
        switch ( Key ) {
        case 'R':
        case 'r':
                Key_r();
                break;
        case 's':
        case 'S':
                Key_s();
                break;
        case 27:	// Escape key
                exit(1);
        }
}

 void SpecialKeyFunc( int Key, int x, int y )
{
        switch ( Key ) {
        case GLUT_KEY_UP:
                Key_up();
                break;
        case GLUT_KEY_DOWN:
                Key_down();
                break;
        }
}

 void Key_r(void)
{
        if ( singleStep ) {			// If ending single step mode
                singleStep = GL_FALSE;
                spinMode = GL_TRUE;		// Restart animation
        }
        else {
                spinMode = !spinMode;	// Toggle animation on and off.
        }
}

void Key_s(void)
{
        singleStep = GL_TRUE;
        spinMode = GL_TRUE;
}

void Key_up(void)
{
    AnimateIncrement *= 2.0;			// Double the animation time step
}

void Key_down(void)
{
    AnimateIncrement /= 2.0;			// Halve the animation time step

}



