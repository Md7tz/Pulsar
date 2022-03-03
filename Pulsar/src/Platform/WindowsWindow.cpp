#include "prpch.h"
#include "WindowsWindow.h"

namespace Pulsar {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) 
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		/* Poll for and process events */
		glfwPollEvents();
		/* Swap front and back buffers */
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::Init(const WindowProps& props) 
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		PR_CORE_INFO("Creating Window {0} ({1} {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) 
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			PR_CORE_ASSERT(success, "Could not initialize GLFW");

			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);

		/* Make the window's context current */
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);	
		
		SetVSync(true);
	}

	void WindowsWindow::Shutdown() 
	{
		glfwDestroyWindow(m_Window);
	}

}