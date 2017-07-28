#include "Engine.hpp"

Engine::Engine()
{
    // Get the screen resolution
    // and create an SFML window and View
    Vector2f resolution;
    resolution.x = 1920;//VideoMode::getDesktopMode().width;
    resolution.y = 1080;//VideoMode::getDesktopMode().height;
    
    m_Window.create(VideoMode(resolution.x, resolution.y),
                    "Thomas was late",
                    Style::Default);
    
    // Initialize the fullscreen view
    m_MainView.setSize(resolution);
    m_HudView.reset(
                    FloatRect(0, 0, resolution.x, resolution.y));
    
    // Inititialize the split screen Views
    m_LeftView.setViewport(
                           FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
    
    m_RightView.setViewport(
                            FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
    
    m_BGLeftView.setViewport(
                             FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
    
    m_BGRightView.setViewport(
                              FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
    
    m_BackgroundTexture = TextureHolder::GetTexture(
                                                    "graphics/background.png"); 
    
    // Associate the sprite with the texture 
    m_BackgroundSprite.setTexture(m_BackgroundTexture); 
    
}

void Engine::run()
{
    // Timing
    Clock clock;
    
    while (m_Window.isOpen())
    {
        Time dt = clock.restart();
        // Update the total game time
        m_GameTimeTotal += dt;
        // Make a decimal fraction from the delta time
        float dtAsSeconds = dt.asSeconds();
        
        // Call each part of the game loop in turn
        input();
        update(dtAsSeconds);
        draw(); 
    } 
}

void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::KeyPressed)
        {
            // Handle the player quitting
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                m_Window.close();
            }
            
            // Handle the player starting the game
            if (Keyboard::isKeyPressed(Keyboard::Return))
            {
                m_Playing = true;
            }
            
            // Switch between Thomas and Bob
            if (Keyboard::isKeyPressed(Keyboard::Q))
            {
                m_Character1 = !m_Character1;
            }
            
            // Switch between full and split screen
            if (Keyboard::isKeyPressed(Keyboard::E))
            { 
                m_SplitScreen = !m_SplitScreen; 
            } 
        } 
    }   
}
