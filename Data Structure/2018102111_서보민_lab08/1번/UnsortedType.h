#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType;

template <class ItemType>
class UnsortedType
{
public:
  UnsortedType();     	
  ~UnsortedType();    

  bool IsFull() const;
  int  LengthIs() const;
  void MakeEmpty();
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item); 
  void DeleteItem(ItemType item);
  void ResetList();
  void GetNextItem(ItemType& item);
  void PrintSumSquares();
private:
  NodeType<ItemType>* listData;
  int length;
  NodeType<ItemType>* currentPos;
};

template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
// Class destructor
{
  MakeEmpty();
}  
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
{
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(bad_alloc exception)
  {
    return true;
  }
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const
{
  return length;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, 
    bool& found)
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
{
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        while (!(item==(location->next)->info))
            location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()
{
  currentPos = NULL;
}
 
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
{
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info;
} 

template <class ItemType>
void UnsortedType<ItemType>::PrintSumSquares()
{
    //a, b, c, d, e�� ������ ���� �� ���
    cout << SumSquares_a(listData) << endl; // a �� �Լ�
    cout << SumSquares_b(listData) << endl; // b �� �Լ�
    cout << SumSquares_c(listData) << endl; // c �� �Լ�
    cout << SumSquares_d(listData) << endl; // d �� �Լ�
    cout << SumSquares_e(listData) << endl; // e �� �Լ�
};

template <class ItemType>
ItemType SumSquares_a(NodeType<ItemType>* list)
// Base case�� ��Ȯ�ϰ� �������� �ʾ� ������ �߻��մϴ�.
// ���� ������ �Լ��� ����Ǹ� �ٷ� 0�� return�ϱ� ������ ����� �������� �ʽ��ϴ�.
{
    if (list == NULL)
        return 0;
    else
        return (list->info * list->info) + SumSquares_a(list->next);
}

template <class ItemType>
ItemType SumSquares_b(NodeType<ItemType>* list)
// ���� ������ list->info�� ������ ���ϴ� �Լ��Դϴ�.
// ������ ���� �����ϵ��� �����ϱ� ���Ͽ� list->info�� ���� �� �����ݴϴ�.
{
    int sum = 0;
    while (list != NULL) {
        sum = list->info * list->info + sum;
        list = list->next;
    }
    return sum;
}

template <class ItemType>
ItemType SumSquares_c(NodeType<ItemType>* list)
// �߸��� �κ��� �����ϴ�.
{
    if (list == NULL)
        return 0;
    else
        return list->info * list->info + SumSquares_c(list->next);
}

template <class ItemType>
ItemType SumSquares_d(NodeType<ItemType>* list)
// �߸��� �κ��� �����ϴ�.
{
    if (list->next == NULL)
        return list->info * list->info;
    else
        return list->info * list->info + SumSquares_d(list->next);
}

template <class ItemType>
ItemType SumSquares_e(NodeType<ItemType>* list)
// ���� ������ info�� �ƴ� node��ü�� ���ϸ�
// ���� info ������ ���� ������ �����ϴ� �κ� ���� �����ϴ�.
{
    if (list == NULL)
        return 0;
    else
        return SumSquares_e(list->next) + list->info * list->info;
}
