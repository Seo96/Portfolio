class NodeType:
    """ Node Type """
    def __init__(self, _name, _id):
        self.name = _name
        self.id = _id
        self.next = None

class SortedType:
    def __init__(self):
        self.listData = None
        self.length = 0
        self.currentPos = None

    def length_is(self):
        return self.length

    def reset_list(self):
        self.currentPos = None

    def get_next_item(self):
        if self.currentPos == None:
            self.currentPos = self.listData
        name, id = self.currentPos.name, self.currentPos.id
        self.currentPos = self.currentPos.next

        return name, id

    def insert_item(self, name, id):
        location = self.listData
        predLoc = None
        moretosearch = location != None
        while moretosearch:
            if location.name < name:
                predLoc = location
                location = location.next
                moretosearch = location != None
            elif location.name == name:
                if location.id < id:
                    predLoc = location
                    location = location.next
                    moretosearch = location != None
                else:
                    moretosearch = False
            else:
                moretosearch = False
        node = NodeType(name, id)
        if predLoc == None:
            node.next = self.listData
            self.listData = node
        else:
            node.next = location
            predLoc.next = node
        self.length += 1

    def __str__(self):
        self.reset_list()
        items = []
        for i in range(0, self.length):
            name, id = self.get_next_item()
            items.append("(" +name + ", " + str(id) + ")\n")
        return "".join(items)
