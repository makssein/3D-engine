#include <scene.hpp>

namespace my{
    Scene::Scene(int width, int height){
        m_width = width;
        m_height = height;
        m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_width, m_height), "3D Engine");
        m_texture = std::make_unique<sf::Texture>();
        m_texture->create(m_width, m_height);
        m_sprite = std::make_unique<sf::Sprite>(*m_texture); // !!!!

        m_camera = std::make_unique<Camera>(m_width, m_height);
    }
    Scene::~Scene(){

    }

    void Scene::LifeCycle(){
        while (m_window->isOpen()) {
            sf::Event event;
            while (m_window->pollEvent(event))
                if (event.type == sf::Event::Closed)
                    m_window->close();

            m_texture->update((uint8_t*)m_camera->Picture(), 1920, 1080, 0, 0); // unsigned char*, int, uint8_t, uint32_t

            m_window->clear();
            m_window->draw(*m_sprite);

            m_window->display();

        }
    }
}
