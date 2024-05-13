#include "commonInclude.h"
#include "context.h"

void OnFramebufferSizeChange(GLFWwindow* window, int width, int height)
{
	SPDLOG_INFO("framebuffer size changed: ({} x {})", width, height);
	glViewport(0, 0, width, height);
}

void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	SPDLOG_INFO("key: {}, scancode: {}, action: {}, mods: {}{}{}",
		key, scancode,
		action == GLFW_PRESS ? "Pressed" : action == GLFW_RELEASE ? "Released"
			: action == GLFW_REPEAT								  ? "Repeat"
																  : "Unknown",
		mods & GLFW_MOD_CONTROL ? "C" : "-",
		mods & GLFW_MOD_SHIFT ? "S" : "-",
		mods & GLFW_MOD_ALT ? "A" : "-");

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int main(int argc, const char** argv)
{
	SPDLOG_INFO("glfw Initialize");
	if (glfwInit() == GLFW_FALSE)
	{
		const char* description = nullptr;
		glfwGetError(&description);

		SPDLOG_ERROR("Failed to initialize glfw: {}", description);
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	SPDLOG_INFO("Create glfw Window");
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
	if (!window)
	{
		SPDLOG_ERROR("Failed to create glfw window");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// OpenGL 함수 로딩
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		SPDLOG_ERROR("Failed to initialize glad");
		glfwTerminate();
		return -1;
	}

	const char* glVersion = (const char*)glGetString(GL_VERSION);
	SPDLOG_INFO("OpenGL context version: {}", glVersion);

	// 윈도우 생성 직후에는 아래 콜백이 호출 되지 않음으로 수동으로 호출
	OnFramebufferSizeChange(window, WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwSetFramebufferSizeCallback(window, OnFramebufferSizeChange);
	glfwSetKeyCallback(window, OnKeyEvent);

	ContextUPtr context = Context::Create();
	if (!context)
	{
		SPDLOG_ERROR("failed to create context");
		glfwTerminate();
		return -1;
	}

	SPDLOG_INFO("Start main loop");
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		//		glClearColor(.0f, .1f, .2f, .0f);
		//		glClear(GL_COLOR_BUFFER_BIT);
		context->Render();
		glfwSwapBuffers(window);
	}
	context.reset();

	glfwTerminate();
	return 0;
}