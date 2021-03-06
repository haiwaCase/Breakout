#include "Ball.h"

Ball::Ball(sf::Vector2f const & position) : BreakoutEntity(position) {
    m_rectangle = sf::RectangleShape{sf::Vector2f{ballSize, ballSize}};
    m_rectangle.setFillColor(sf::Color::White);

    m_rectangle.setPosition(m_position);
}

void Ball::update() {
    sf::Time dt = m_clock.restart();
    move(dt);
}

void Ball::render(sf::RenderWindow & renderWindow) {
    renderWindow.draw(m_rectangle);
}

void Ball::move(sf::Time dt) {
    m_position.x += m_ballSpeedMoveX * dt.asSeconds() * cos((48) / 180.f * M_PI);
    m_position.y += m_ballSpeedMoveY * dt.asSeconds() * sin((48) / 180.f * M_PI);

    if (m_position.x < 0) m_ballSpeedMoveX *= -1;
    if (m_position.x > 800) m_ballSpeedMoveX *= -1;
    if (m_position.y < 0) m_ballSpeedMoveY *= -1;
    if (m_position.y > 600) m_ballSpeedMoveY *= -1;

    m_rectangle.setPosition(m_position);
}
