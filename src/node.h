#pragma once
#include <QMap>
#include <QVector>

enum NodeType {
  Null,
  Element,
  TextNode,
};

class Node {
 public:
  Node() { m_type = NodeType::Null; }
  Node(QString data) {
    m_type = NodeType::TextNode;
    m_text = data;
  };
  Node(QString tag_name, QMap<QString, QString> attrs, QVector<Node> children) {
    m_type = NodeType::Element;
    m_text = tag_name;
    m_attrs = attrs;
    m_children = children;
  }

  NodeType type() { return m_type; }
  QMap<QString, QString> attrs() { return m_attrs; }
  QVector<Node> children() { return m_children; }
  QString text() { return m_text; }

 private:
  NodeType m_type;
  QMap<QString, QString> m_attrs;
  QVector<Node> m_children;
  QString m_text;
};
