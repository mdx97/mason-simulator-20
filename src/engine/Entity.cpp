#include "engine/Entity.h"

Composite::Composite()
{
    type = "";
}

void Composite::AddEntity(Entity *entity)
{
    entities.push_back(entity);
    entity->composite = this;
}

void Composite::RemoveEntity(Entity *entity)
{
    auto iter = std::find(entities.begin(), entities.end(), entity);

    if (iter != entities.end()) {
        entities.erase(iter);
    }
}

Entity::Entity()
{
    x = 0;
    y = 0;
    type = "";
    composite = nullptr;
}

Entity::~Entity()
{
    for (auto component : components) {
        delete component;
    }

    if (composite != nullptr) {
        composite->RemoveEntity(this);
    }
}

void Entity::AddComponent(Component *component)
{
    components.push_back(component);
    component->entity = this;
}

// template <typename T>T* Entity::GetComponent()
// {
//     T *casted = nullptr;

//     for (auto component : components) {
//         casted = dynamic_cast<T *>(component);
//         if (casted != nullptr) {
//             break;
//         }
//     }

//     return casted;
// }
