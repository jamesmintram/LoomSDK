#pragma once 

// a GL Context which is externally managed

namespace bgfx 
{
	struct SwapChainGL;
	
    struct GlContext
    {
        GlContext()
            : m_view(0), m_context(0)
        {

        }

#if BX_PLATFORM_IOS
        static int fbo;
        static int msaaFbo;
#endif
        
        void create(uint32_t _width, uint32_t _height);
        void destroy();
        void resize(uint32_t _width, uint32_t _height, bool _vsync);

        static bool isSwapChainSupported();

        void swap();
        void import();
        
        bool isValid() const
        {
            return 0 != m_context;
        }

        void* m_view;
        void* m_context;
    };
} // namespace bgfx


