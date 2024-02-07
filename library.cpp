#include <SFML/Graphics.hpp>
#include <vector>

struct ChartData {
    std::string label;
    int value;
    sf::Color color;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Data Analyzing");
    sf::CircleShape chart[3];
    std::vector<ChartData> data = {
        {"Category 1", 25, sf::Color::Red},
        {"Category 2", 50, sf::Color::Blue},
        {"Category 3", 25, sf::Color::Yellow}
    };
    float total = 0;
    for (auto& d : data) {
        total += d.value;
    }
    float curAngle = 0;
    for (int i = 0; i < 3; i++) {
        chart[i].setPosition(400, 300);
        chart[i].setRadius(200);
        chart[i].setFillColor(sf::Color::Transparent);
        chart[i].setOutlineThickness(10);
        chart[i].setOutlineColor(data[i].color);
        float sliceAngle = (float)data[i].value / total * 3.14 * 2;
        sf::Vertex vertices[100];
        for (int j = 0; j < 100; j++) {
            float angle = curAngle + j * sliceAngle / 100;
            vertices[j].position = chart[i].getPosition() + sf::Vector2f(
                200 * std::cos(angle),
                200 * std::sin(angle)
            );
            vertices[j].color = data[i].color;
        }
        chart[i].setPoints(vertices, 100);
        curAngle += sliceAngle;
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        for (int i = 0; i < 3; i++) {
            window.draw(chart[i]);
        }
        window.display();
    }
    return 0;
}