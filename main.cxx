#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

/**
 * Draw a Triangle on OSX 10.15.4 ( Catalina )
 * Code was originally from:
 *   http://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/
 */

int main ( void ) {

	glfwWindowHint( GLFW_SAMPLES, 4 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

	GLFWwindow *window;

	if ( !glfwInit() ) {
		return -1;
	}

	window = glfwCreateWindow( 640, 480, "Jupiter", NULL, NULL );
	if ( !window ) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent( window );

	glewExperimental = true; // Needed in core profile
	if ( glewInit() != GLEW_OK ) {
		fprintf( stderr, "Failed to initialize GLEW\n" );
		return -1;
	}

	/**
	 * VAO
	 */
	GLuint VertexArrayID;
	glGenVertexArrays( 1, &VertexArrayID );
	glBindVertexArray( VertexArrayID );

	// An array of 3 vectors which represents 3 vertices
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	glGenBuffers( 1, &vertexbuffer );
	glBindBuffer( GL_ARRAY_BUFFER, vertexbuffer );
	glBufferData( GL_ARRAY_BUFFER, sizeof( g_vertex_buffer_data ), g_vertex_buffer_data, GL_STATIC_DRAW );

	/**
	 * Loop Until window's context current
	 */
	while ( !glfwWindowShouldClose( window ) ) {

		glClear( GL_COLOR_BUFFER_BIT );

		glEnableVertexAttribArray( 0 );
		glVertexAttribPointer(
				0,
				3,
				GL_FLOAT,
				GL_FALSE,
				0,
				( void* )0
				);

		glClearColor( 0.5f, 0.4f, 0.3f, 0.2f );

		glDrawArrays( GL_TRIANGLES, 0, 3 );
		glDisableVertexAttribArray( 0 );


		glfwSwapBuffers( window );

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
