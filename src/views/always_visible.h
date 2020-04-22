#pragma once

#include "visible.h"

class AlwaysVisible : public Visible {
public:
    bool GetVisibility() override;
};
