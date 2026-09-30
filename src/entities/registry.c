#include "entities/registry.h"
#include "entities/person.h"
#include "entities/vehicle.h"
#include <stdio.h>
#include <string.h>

#define SAVE_FILE_NAME "vehicle_registry_save.bin"
#define BINARY_WRITE_MODE "wb"
#define BINARY_READ_MODE "rb"

bool initialize_registry_from_save_file(struct Registry *registry)
{
    FILE *file_pointer = fopen(SAVE_FILE_NAME, BINARY_READ_MODE);

    bool file_exists = file_pointer != NULL;

    if (!file_exists)
    {
        return false;
    }

    int elements_read =
        fread(registry, sizeof(struct Registry), 1, file_pointer);

    bool is_read_successful = elements_read == 1;

    return is_read_successful;
}

bool persist_registry(struct Registry registry)
{
    FILE *file_pointer = fopen(SAVE_FILE_NAME, BINARY_WRITE_MODE);

    bool is_file_opened_successfully = file_pointer != NULL;
    if (!is_file_opened_successfully)
    {
        return false;
    }

    int elements_written =
        fwrite(&registry, sizeof(struct Registry), 1, file_pointer);

    if (elements_written != 1)
    {
        return false;
    }

    int fclose_result = fclose(file_pointer);

    bool is_file_closed_successfully = fclose_result != EOF;

    return is_file_closed_successfully;
}

int find_vehicle_index_by_owner_name(struct Registry *registry,
                                     char *owner_name)
{
    int left = 0;
    int right = registry->vehicle_count - 1;

    while (left <= right)
    {
        int middle = left + ((right - left) / 2);

        if (strstr(registry->vehicles[middle].owner.name, owner_name))
        {
            return middle;
        }

        if (strncmp(registry->vehicles[middle].owner.name, owner_name,
                    MAX_NAME_SIZE) < 0)
        {
            left = middle + 1;
            right = registry->vehicle_count - 1;
            continue;
        }

        if (strncmp(registry->vehicles[middle].owner.name, owner_name,
                    MAX_NAME_SIZE) > 0)
        {
            right = middle - 1;
            continue;
        }
    }

    return -1;
}

void initialize_registry_with_default_values(struct Registry *registry)
{
    registry->vehicle_count = 0;
}

void sort_registry_by_owner_name(struct Registry *registry)
{
    for (int i = 0; i < registry->vehicle_count; i++)
    {
        for (int j = 0; j < registry->vehicle_count - 1; j++)
        {
            if (strncmp(registry->vehicles[j].owner.name,
                        registry->vehicles[j + 1].owner.name,
                        MAX_NAME_SIZE) > 0)
            {
                struct Vehicle temp = registry->vehicles[j];
                registry->vehicles[j] = registry->vehicles[j + 1];
                registry->vehicles[j + 1] = temp;
            }
        }
    }
}

bool push_back_vehicle_to_registry(struct Registry *registry,
                                   struct Vehicle vehicle)
{
    if (registry->vehicle_count >= MAX_VEHICLE_REGISTRY_CAPACITY)
    {
        return false;
    }

    registry->vehicles[registry->vehicle_count] = vehicle;
    registry->vehicle_count++;

    return true;
}

void print_registry_contents(struct Registry *registry)
{
    for (int i = 0; i < registry->vehicle_count; i++)
    {
        printf("(%d) ", i + 1);
        print_vehicle(&(registry->vehicles[i]));
    }
}

bool is_registry_full(struct Registry *registry)
{
    return registry->vehicle_count >= MAX_VEHICLE_REGISTRY_CAPACITY;
}

bool is_registry_empty(struct Registry *registry)
{
    return registry->vehicle_count == 0;
}

bool remove_vehicle_from_registry(struct Registry *registry,
                                  int vehicle_position)
{
    if (is_registry_empty(registry) ||
        vehicle_position >= registry->vehicle_count)
    {
        return false;
    }

    for (int i = vehicle_position; i < registry->vehicle_count - 1; i++)
    {
        registry->vehicles[i] = registry->vehicles[i + 1];
    }

    registry->vehicle_count--;

    return true;
}

bool is_registry_sorted(struct Registry *registry)
{
    for (int i = 0; i < registry->vehicle_count - 1; i++)
    {
        if (strncmp(registry->vehicles[i].owner.name,
                    registry->vehicles[i + 1].owner.name, MAX_NAME_SIZE) > 0)
        {
            return false;
        }
    }

    return true;
}
