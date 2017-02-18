//
// Created by naliwe on 7/15/16.
//

#ifndef KENGINE_COMPONENTFACTORY_HPP
# define KENGINE_COMPONENTFACTORY_HPP

# include <memory>
# include "Component.hpp"

class ComponentFactory final
{
public:
    ComponentFactory()
    {}

public:
    ComponentFactory(ComponentFactory const& o) = delete;
    ComponentFactory& operator=(ComponentFactory const&) = delete;

    ComponentFactory(ComponentFactory&&) = default;
    ComponentFactory& operator=(ComponentFactory&&) = default;

public:
    template<class CT, class... Args,
             typename = std::enable_if_t<
                     std::is_base_of<IComponent, CT>::value>>
    static constexpr auto createComponent(std::string const& name, Args&& ... params) noexcept
    {
        std::unique_ptr<CT> ret(nullptr);
        ret.reset(new CT(name, std::forward<Args>(params)...));

        return ret;
    }
};


#endif //KENGINE_COMPONENTFACTORY_HPP
