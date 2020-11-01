#include "entity.h"
#include "account_balance.h"
#include "component/text.h"
#include <string>


namespace component {

AccountBalance::AccountBalance(): money_(1000) {}

AccountBalance::AccountBalance(int money): money_(money) {}

int AccountBalance::Get() {
	return money_;
}


void AccountBalance::ChangeText(Entity* entity) {
	if (entity->HasComponent<component::AccountBalance>() &&
		entity->HasComponent<component::Text>()) {

		component::AccountBalance* balance = 
			entity->GetComponent<component::AccountBalance>();
		
		component::Text* text = 
			entity->GetComponent<component::Text>();
		
		std::string balance_text = "Balance: ";
		
		balance_text += std::to_string(balance->Get());

		text->SetText(balance_text);
	}
}

bool AccountBalance::ChangeMoney(Entity* entity, int delta_money) {
	auto balance = entity->GetComponent<component::AccountBalance>();
	if (balance->Get() + delta_money >= 0) {
		balance->money_ += delta_money;
		ChangeText(entity);
		return true;
	}
	else {
		return false;
	}
}

}
