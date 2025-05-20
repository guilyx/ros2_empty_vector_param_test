# ROS2 Vector Parameter Test

The repository provides a simple test environment for ROS2 parameter management using Docker. **It highlights the issue of getting an exception when using `RewrittenYaml` on empty vectors in parameter files.**

## Project Structure

```
.
├── docker/
│   ├── Dockerfile
│   └── docker-compose.yml
├── empty_vector_param_test/
│   ├── config/
│   │   └── params.yaml
│   ├── launch/
│   │   └── vector_param_test.launch.py
│   ├── src/
│   │   └── vector_param_node.cpp
│   ├── CMakeLists.txt
│   └── package.xml
├── .dockerignore
├── .gitignore
└── README.md
```

## Prerequisites

- Docker
- Docker Compose

## Building and Running

### Using Docker (Recommended)

Build and run using Docker Compose:
```bash
docker-compose -f docker/docker-compose.yml up --build
```


## Parameter Configuration

The default parameter configuration is in `empty_vector_param_test/config/params.yaml`:

```yaml
vector_param_node:
  ros__parameters:
    test_vector: [""]  # Empty vector parameter
    test_param: "test_value"
```

You can modify this file to test different vector parameter configurations.

## Launch Arguments

