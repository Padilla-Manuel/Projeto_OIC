# 📡 Sistema de Monitoramento por Zonas de Veículos de Serviço e Segurança em Smart Campus

## 📖 Sobre o Projeto

Este projeto tem como objetivo desenvolver uma solução IoT para monitoramento de veículos de serviço e segurança em ambientes Smart Campus.

A proposta consiste em identificar a localização aproximada dos veículos por meio de zonas previamente definidas e monitorar seu estado operacional (EM MOVIMENTO ou PARADO), permitindo a geração de alertas em tempo real e o armazenamento dos dados para análises futuras.

O sistema foi desenvolvido utilizando ESP32, MQTT, Node-RED, Telegram, InfluxDB e Grafana, simulando uma arquitetura completa de Internet das Coisas aplicada ao contexto acadêmico.

---

## 🎯 Objetivos

- Monitorar veículos de serviço e segurança dentro do campus;
- Identificar automaticamente a zona onde o veículo se encontra;
- Detectar estados de movimentação e parada;
- Gerar alertas automáticos em tempo real;
- Armazenar dados históricos para análise;
- Disponibilizar dashboards para monitoramento operacional.

---

## 🏗️ Arquitetura do Sistema

```text
ESP32 + Sensor
       │
       ▼
 Broker MQTT (HiveMQ)
       │
       ▼
    Node-RED
(Processamento de Dados)
       │
       ├────────► Telegram
       │          (Alertas)
       │
       ▼
 InfluxDB Cloud
       │
       ▼
    Grafana
 (Dashboards)
```

---

## 🔧 Tecnologias Utilizadas

### Hardware

- ESP32
- Potenciômetro (simulação de localização)
- LED

### Software

- Arduino IDE
- MQTT
- HiveMQ Broker
- Node-RED
- Telegram Bot API
- InfluxDB Cloud
- Grafana
- Wokwi

---

## 🚗 Funcionamento

O potenciômetro conectado ao ESP32 simula a movimentação do veículo entre diferentes regiões do campus.

### Zonas Monitoradas

| Faixa de Valor | Zona |
|---------------|-------|
| 0 - 999 | Portaria 1 |
| 1000 - 1999 | Portaria 2 |
| 2000 - 2999 | Portaria 3 |
| 3000 - 4095 | Portaria 4 |

### Estados Monitorados

- EM MOVIMENTO
- PARADO

As informações são enviadas em formato JSON para o broker MQTT.

### Exemplo de mensagem MQTT

```json
{
  "zona":"Portaria 2",
  "status":"EM MOVIMENTO",
  "valor":1185
}
```

---

## 🧠 Regras de Negócio

### Identificação da Zona

O sistema identifica automaticamente a portaria atual do veículo utilizando o valor analógico recebido pelo ESP32.

### Identificação do Status

- Diferença superior a 80 unidades → EM MOVIMENTO
- Diferença inferior ou igual a 80 unidades → PARADO

### Alertas

Sempre que um evento é identificado, o Node-RED gera uma mensagem automática contendo:

- Status do veículo;
- Portaria atual;
- Horário do evento.

---

## 📨 Integração com Telegram

O Node-RED processa os dados recebidos e envia notificações automáticas para um bot do Telegram.

### Exemplos de Alertas

```text
Veículo PARADO na Portaria 1
```

```text
Veículo EM MOVIMENTO na Portaria 3
```

---

## 💾 Banco de Dados

O projeto utiliza o InfluxDB Cloud para armazenamento histórico dos eventos gerados pelo sistema.

Os dados armazenados incluem:

- Zona;
- Status;
- Valor do sensor;
- Data e hora do evento.

---

## 📊 Dashboards Grafana

Os dashboards serão desenvolvidos utilizando Grafana para visualização em tempo real dos indicadores do sistema.

<img width="1093" height="543" alt="img1" src="https://github.com/user-attachments/assets/b4eeec55-bada-4b19-b630-977e1473e95a" />


<img width="1089" height="537" alt="img2" src="https://github.com/user-attachments/assets/42238787-c1f8-4a30-b69a-ff6d8d04ac7b" />


<img width="1091" height="537" alt="image" src="https://github.com/user-attachments/assets/3edf8d87-db9d-4b62-a18d-c0eee1d34fa0" />


### Indicadores

- Veículos por zona;
- Histórico de movimentação;
- Frequência de alertas;
- Eventos por período;
- Status atual do veículo.

---

## 📂 Estrutura do Repositório

```text
📁 Projeto_OIC
│
├── 📁 Wokwi
│   ├── diagram.json
│   ├── libraries.txt
│   ├── sketch.ino
│   └── wokwi-project.txt
│
├── 📁 node-red
│   └── fluxo-node-red.json
│
└── README.md
```

---

## 📹 Vídeo de Demonstração

https://www.youtube.com/watch?v=rrTZLON0EGM

---

## 👨‍💻 Equipe

Projeto desenvolvido para a disciplina de Objetos Inteligentes Conectados.

**Universidade Presbiteriana Mackenzie**

**Curso:** Sistemas de Informação

---

## 📚 Referências

BANDEIRA, Lucilene; BANDEIRA, Bruno; ARAÚJO NETO, Mario de Sousa; CASIMIRO, Adelaide. *Smart Campus no Brasil: um estudo exploratório*. Congresso do Instituto Franco-Brasileiro de Administração de Empresas (IFBAE), 2021.

Disponível em:

https://ifbae.s3.eu-west-3.amazonaws.com/file/congres/smart-campus-no-brasil-bandeira-etal-640711e03213c507448668.pdf

ONU – Objetivos de Desenvolvimento Sustentável (ODS)

https://brasil.un.org/pt-br/sdgs
