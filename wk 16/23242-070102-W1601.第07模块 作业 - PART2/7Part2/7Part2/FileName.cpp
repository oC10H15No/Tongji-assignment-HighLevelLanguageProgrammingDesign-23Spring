#include <iostream>
#include <limits>
using namespace std;

template <class T> class List;
// ��������ڵ���
template <class T>
class ListNode {
    friend class List<T>; // ��Ԫ������
private:
    T data;         // �ڵ�����
    ListNode* next; // ָ����һ���ڵ��ָ��

    template <class> friend class ListIterator; // Add this line to make ListIterator a friend class
public:
    ListNode() : next(nullptr) {}  // Ĭ�Ϲ��캯��
    ListNode(T val) : data(val), next(nullptr) {} // �������Ĺ��캯��
};

// ���������������
template <typename T>
class ListIterator {
public:
    ListNode<T>* current; // ��ǰ�ڵ�ָ��

    ListIterator(ListNode<T>* node) : current(node) {} // ���캯��

    // ���� != �����������ڱȽ������������Ƿ����
    bool operator!=(const ListIterator& other) const {
        return current != other.current;
    }

    // ���� * �����������ڻ�ȡ��ǰ�ڵ������
    T& operator*() {
        return current->data;
    }

    // ���� ++ �����������ڽ��������ƶ�����һ���ڵ�
    ListIterator& operator++() {
        current = current->next;
        return *this;
    }
};

// ����������
template <class T>
class List {
private:
    ListNode<T>* head; // ����ͷָ��
    ListNode<T>* tail; // ����βָ��

public:
    List() : head(nullptr), tail(nullptr) {}                     // Ĭ�Ϲ��캯��
    List(T val) { head = new ListNode<T>(val), tail = nullptr; } // �������Ĺ��캯��
    ~List() { clear(); }                                         // �����������������

    // ������β������½ڵ�
    void push_back(T val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // �ж������Ƿ�Ϊ��
    bool empty() const {
        return head == nullptr;
    }

    // �������
    void clear() {
        ListNode<T>* current = head;
        while (current) {
            ListNode<T>* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }

    // ����ָ������ͷ���ĵ�����
    ListIterator<T> begin() const {
        return ListIterator<T>(head);
    }

    // ����ָ������β���ĵ�����
    ListIterator<T> end() const {
        return ListIterator<T>(nullptr);
    }

    // ����������
    int size() const {
        int count = 0;
        ListNode<T>* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    // ���������� val ��Ԫ��
    ListNode<T>* search(T val) {
        ListNode<T>* current = head;
        while (current) {
            if (current->data == val) return current; // �ҵ�
            current = current->next;
        }
        return nullptr; // û�ҵ����ؿ�ָ��
    }

    // ������ i ��Ԫ�صĵ�ַ
    ListNode<T>* locate(int i) {
        if (i < 0) return nullptr;
        ListNode<T>* current = head;
        int count = 0;
        while (current && count < i) {
            current = current->next;
            count++;
        }
        return current; // ���ص� i ��Ԫ�صĵ�ַ
    }

    // ȡ���� i ��Ԫ�ص�ֵ
    T* getData(int i) {
        if (i < 0) return nullptr;
        ListNode<T>* node = locate(i);
        if (node) return &(node->data); // ����Ѱ�ҵ��Ľ���ַ
        return nullptr; // �������ɹ����ؿ�ֵ
    }

    // �� val �޸ĵ� i ��Ԫ�ص�ֵ
    void setData(int i, T& val) {
        if (i < 0) return;
        ListNode<T>* node = locate(i);
        if (node) node->data = val;
    }

    // �� val ���뵽����� i ��Ԫ��
    bool insert(int i, T& val) {
        if (i < 0) return false; // �Ƿ�ֵ
        ListNode<T>* newNode = new ListNode<T>(val); // �����ڵ�
        if (i == 0) { // ���뵽ͷ�ڵ�
            newNode->next = head; // ��������
            head = newNode;
            if (!tail) tail = newNode;
            return true; // �ɹ�����
        }
        ListNode<T>* prev = locate(i - 1); // ��λ�� i-1 ��Ԫ��
        if (prev) {
            newNode->next = prev->next; // ��������
            prev->next = newNode;
            if (!newNode->next) {
                tail = newNode; // ����ֵ����Ԫ��
            }
            return true; // �ɹ�����
        }
        delete newNode; // ɾ��
        return false; // δ�ɹ����뷵�� false
    }

    // ��������ɾȥ�� i ��Ԫ��
    bool remove(int i) {
        if (i < 0 || !head) return false; // �Ƿ�ֵ
        if (i == 0) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
            if (!head) tail = nullptr;
            return true; // �ɹ�ɾ��
        }
        ListNode<T>* prev = locate(i - 1); // ��λ�� i-1 ��Ԫ��
        if (prev && prev->next) { // ǰ��ǿ�
            ListNode<T>* temp = prev->next; // ��ɾ��Ԫ�����ӵ� temp
            prev->next = temp->next;
            if (!prev->next) {
                tail = prev; // ����βָ��
            }
            delete temp; // ɾ�� temp
            return true; // �ɹ�ɾ��
        }
        return false; // δ�ɹ�ɾ��
    }

    // ���ظ�ֵ������
    List<T>& operator=(List<T>& L) {
        if (this != &L) {
            clear();
            ListNode<T>* current = L.head;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }
};

// ��ȡ�û����룬��������
List<int> readList() {
    List<int> lst;
    int num;

    bool validInput = false;

    while (!validInput) {
        validInput = true;

        while (true) {
            cin >> num;
            // ��������Ƿ�Ϸ�
            if (cin.fail() || (num < -1 && num != 0)) {
                cerr << "����������������-1������" << endl;
                validInput = false;
                lst.clear();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            else if (num == -1) {
                break;
            }
            else {
                lst.push_back(num);
            }
        }
    }

    return lst;
}

// Ѱ����������Ľ���
List<int> findIntersectionLists(const List<int>& lst1, const List<int>& lst2) {
    List<int> result;

    ListIterator<int> it1 = lst1.begin();
    ListIterator<int> it2 = lst2.begin();

    // ������������Ѱ�ҽ���
    while (it1 != lst1.end() && it2 != lst2.end()) {
        if (*it1 == *it2) {
            result.push_back(*it1);
            ++it1;
            ++it2;
        }
        else if (*it1 > *it2) {
            ++it2;
        }
        else {
            ++it1;
        }
    }

    return result;
}

// ��ӡ����
void printList(const List<int>& lst) {
    if (lst.empty()) {
        cout << "NULL" << endl;
    }
    else {
        for (ListIterator<int> it = lst.begin(); it != lst.end(); ++it) {
            if (it != lst.begin()) {
                cout << " ";
            }
            cout << *it;
        }
        cout << endl;
    }
}

int main() {
    cout << "�������һ���������ɸ����������ɵķǽ������У���-1��ʾ��β�������ÿո�������";
    List<int> lst1 = readList(); // ��ȡ��һ������
    cout << "������ڶ�������";
    List<int> lst2 = readList(); // ��ȡ�ڶ�������

    List<int> result = findIntersectionLists(lst1, lst2); // Ѱ�ҽ���
    cout << "��������Ϊ��";
    printList(result); // ��ӡ����

    return 0;
}