cleos push action inventory additem '["orange","8"]' -p orange
cleos push action inventory additem '["mango", "2"]' -p mango
cleos push action inventory removeitem '["orange"]' -p orange
cleos push action inventory additem '["mango", "3"]' -p mango
cleos push action inventory additem '["orange"]' -p orange
cleos push action inventory incfruit '["orange", "2"]' -p orange
cleos push action inventory decfruit '["orange", "3"]' -p orange
cleos push action inventory decfruit '["orange", "2"]' -p orange
cleos get table inventory inventory fruits
cleos push action inventory emptyall '["inventory"]' -p inventory
