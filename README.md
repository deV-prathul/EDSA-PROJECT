# EDSA-PROJECT

Assignment Question 3: Autonomous Crane Fabrication Unit 
Scenario: You’re designing an Autonomous Crane Fabrication Unit for assembling crane parts (e.g., "Boom", "Counterweight", "Cable", "Hook", "Base") in a construction yard. The unit uses:
●	Part Delivery System (Queue): Parts arrive via trucks and queue for fabrication.
●	Crane Task Manager (Stack): Robots stack parts in LIFO order for load balancing.
●	Assembly Storage Unit (Array): Finished cranes store in an array-based yard (size: 6 slots). If full, the oldest is deployed.
●	Repair and Upgrade Tracker (Linked Lists):
○	Faulty cranes go to a singly linked list.
○	Repaired cranes move to a doubly linked list for dual checks.
○	High-priority cranes cycle in a circular linked list for urgent upgrades.
Objective: Simulate crane assembly, storage, and repair.
Tasks:

a) Part Delivery and Crane 
●	Simulate 6 parts (e.g., "Boom", "Counterweight", "Cable", "Hook", "Base", "Pulley") in a queue.
●	Robots stack them in LIFO order. Write pseudocode or an algorithm to:
○	Enqueue all 6 parts.
○	Dequeue and push onto a stack.
○	Pop to show assembly order.
●	Creativity Bonus: Describe (in 2-3 sentences) why LIFO fits (e.g., "Hook" last for lifting readiness).
b) Assembly Storage Unit 
●	Store cranes in a 6-slot array.
●	Simulate adding 8 cranes (e.g., "Crane1", "Crane2", ..., "Crane8"). If full, deploy the oldest. Write pseudocode or an algorithm to:
○	Insert the first 6 cranes.
○	Handle overflow for "Crane7" and "Crane8".
●	Creativity Bonus: Suggest (in 2-3 sentences) a reason for deployment (e.g., site demand urgency).
c) Faulty Crane Tracker 
●	"Crane2" and "Crane5" are faulty. Add to a singly linked list.
●	Move "Crane2" to a doubly linked list post-repair. Write pseudocode or an algorithm to:
○	Insert "Crane2" and "Crane5".
○	Delete "Crane2" and insert it into the doubly linked list.
○	Traverse forward and backward.
●	Creativity Bonus: Propose (in 2-3 sentences) a fault and fix (e.g., "Crane2’s cable frayed, replaced by bots").
d) Priority Upgrades 
●	"Crane1" and "Crane4" need upgrades (e.g., extended reach). Add to a circular linked list. Write pseudocode or an algorithm to:
○	Insert "Crane1" and "Crane4".
○	Traverse twice.
●	Creativity Bonus: Invent (in 2-3 sentences) an upgrade (e.g., "Crane4 gets a magnetic grip").

