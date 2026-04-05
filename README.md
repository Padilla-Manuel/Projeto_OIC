# 📡 Sistema de monitoramento por zonas de veículos de serviço e segurança em Smart Campus 

---

## 📌 Descrição do Projeto

Este projeto implementa um sistema IoT para monitoramento de veículos de serviço e segurança em um ambiente de **Smart Campus**, com foco na validação de uma arquitetura completa de coleta, processamento e visualização de dados.

Diferente de soluções tradicionais baseadas em GPS, o sistema utiliza uma **abstração espacial por zonas**, permitindo:

- Redução de complexidade computacional e custo  
- Validação dos fluxos de dados e integração entre sistemas  
- Teste de regras de negócio em tempo real  

### 🎯 Funcionalidades principais

- Identificação da **zona atual do veículo**
- Detecção de estado (**movimento / parado**)
- Geração de **alertas automáticos**
- Armazenamento de dados históricos
- Visualização em dashboards analíticos

---

## 🧠 Arquitetura do Sistema

```text
[Dispositivo IoT]
      │ (JSON via MQTT)
      ▼
   [Broker MQTT]
      ▼
   [Node-RED]
(Processamento + Regras)
      ▼
 [InfluxDB Cloud]
      ▼
    [Grafana]

```

## 📹 link do video
