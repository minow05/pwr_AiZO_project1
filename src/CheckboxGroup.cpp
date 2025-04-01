#include "../include/UI/CheckboxGroup.h"

CheckboxGroup::CheckboxGroup(std::vector<Checkbox> checkboxes, std::vector<sf::Text> labels) : checkboxes(checkboxes), labels(labels) {
}

void CheckboxGroup::handleEvent(sf::RenderWindow &window) {
    for (auto & checkbox : checkboxes) {
        checkbox.checked = false;
        checkbox.handleEvent(window);
    }
}

void CheckboxGroup::render(sf::RenderWindow &window) {
    for (auto &checkbox : checkboxes) {
        checkbox.render(window);
    }
    for (auto &label : labels) {
        window.draw(label);
    }
}

Checkbox* CheckboxGroup::getCheckedId() {
    for (auto &checkbox : checkboxes) {
        if (!checkbox.checked) continue;
        return &checkbox;
    }
    return nullptr;
}

void CheckboxGroup::addCheckbox(Checkbox &checkbox) {
    checkboxes.push_back(checkbox);
}
